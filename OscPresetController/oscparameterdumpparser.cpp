#include "oscparameterdumpparser.h"
#include "osccontrolledfloat.h"
#include "osccontrolledbool.h"
#include "osccontrolledquad2f.h"
#include "osccontrolledenum.h"
OscParameterDumpParser::OscParameterDumpParser(QObject *parent) :
        QObject(parent)
{
}

QList<OscControlledState*> OscParameterDumpParser::parseFile(QString filename, QObject *parent){
    QList<OscControlledState*> result;
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))return(result);


    while (!file.atEnd()) {
        QString line = file.readLine();
        QStringList parts= line.split("\t");
        //here we decide which kind of setting to construct from the saved data
        if(parts.length()>0){
            if(parts.at(0)=="float"&&parts.length()==6){
                result.push_back(new OscControlledFloat(
                        parts.at(1),
                        parts.at(2),
                        parts.at(3).toFloat(),
                        parts.at(4).toFloat(),
                        parts.at(5).toFloat(),
                        parent
                        ));
            } else if(parts.at(0)=="int"&&parts.length()==6){
                result.push_back(new OscControlledInt(
                        parts.at(1),
                        parts.at(2),
                        parts.at(3).toFloat(),
                        parts.at(4).toFloat(),
                        parts.at(5).toFloat(),
                        parent
                        ));
            } else if (parts.at(0)=="trigger"&&parts.length()==3){
                result.push_back(new OscControlledTrigger(
                        parts.at(1),
                        parts.at(2).trimmed(),
                        parent
                        ));
            } else if (parts.at(0)=="mouseRelay"&&parts.length()==3){
                result.push_back(new OscControlledMouseRelay(
                        parts.at(1),
                        parts.at(2).trimmed(),
                        parent
                        ));
            } else if (parts.at(0)=="bool"&&parts.length()==4){
                result.push_back(new OscControlledBool(
                        parts.at(1),
                        parts.at(2),
                        parts.at(3).toInt()>0,
                        parent
                        ));
            } else if (parts.at(0)=="string"&&parts.length()>=4){
                result.push_back(new OscControlledString(
                        parts.at(1),
                        parts.at(2),
                        parts.at(3).trimmed(),
                        parent
                        ));
            } else if (parts.at(0)=="floatVector"&&parts.length()>=4){
                //check number of components
                int nComp=parts.at(3).toInt();
                if(nComp>0 &&parts.length()==4+4*nComp){
                    QList<QString> componentNames;
                    QList<double> currentValues;
                    QList<double> minValues;
                    QList<double> maxValues;
                    int curPart=4;
                    //component names
                    for(int i = 0; i<nComp;i++){componentNames.append(parts.at(curPart));curPart++;}
                    //current values
                    for(int i = 0; i<nComp;i++){currentValues.append(parts.at(curPart).toFloat());curPart++;}
                    //min values
                    for(int i = 0; i<nComp;i++){minValues.append(parts.at(curPart).toFloat());curPart++;}
                    //max values
                    for(int i = 0; i<nComp;i++){maxValues.append(parts.at(curPart).toFloat());curPart++;}
                    //build the setting instance
                    result.push_back(new OscControlledFloatVector(
                            parts.at(1),
                            parts.at(2),
                            componentNames,
                            currentValues,
                            minValues,
                            maxValues,
                            parent
                            ));
                }


            }else if (parts.at(0)=="quad2f"&&parts.length()==15){
                QPointF corners[4];
                QPointF minValue;
                QPointF maxValue;

                minValue.setX(parts.at(3).toDouble());
                minValue.setY(parts.at(4).toDouble());
                maxValue.setX(parts.at(5).toDouble());
                maxValue.setY(parts.at(6).toDouble());
                for(int i=0;i<4;i++){
                    corners[i].setX(parts.at(7+i*2).toDouble());
                    corners[i].setY(parts.at(7+i*2+1).toDouble());
                }
                result.push_back(new OscControlledQuad2f(
                        parts.at(1),
                        parts.at(2),
                        minValue,
                        maxValue,
                        corners,
                        parent
                        ));

            }else if (parts.at(0)=="enum"){
                //check number of states
                int nComp=parts.at(3).toInt();
                if(nComp>0 &&parts.length()==5+nComp){
                    QList<QString> stateNames;
                    int curPart=4;
                    //component names
                    for(int i = 0; i<nComp;i++){stateNames.append(parts.at(curPart));curPart++;}
                    int currentValue=parts.at(4+nComp).toInt();
                    //build the setting instance
                    result.push_back(new OscControlledEnum(
                            parts.at(1),
                            parts.at(2),
                            stateNames,
                            currentValue,
                            parent
                            ));
                }
            }



        }//(parts.length()>0)
    }//(!file.atEnd())
    return(result);
}
