#include "osccontrolledfloatvector.h"
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include "multislidersettingwidget.h"
//#include "vectorpadwidget.h"
#include <QDebug>



// take the current value of another instance. must be implemented by derived classes. checks for right key and type.
void OscControlledFloatVector::setFromState(OscControlledState* source){
    if((source->getType()==this->getType())&&source->getAdress()==this->getAdress()){
        if(source->getAsDoubleList().length()==this->currentValues.length()){
            this->currentValues=source->getAsDoubleList();
        }else{
            qWarning()<<"Tried to set "<<this->description<< "with wrong number of float list entries\n";
        }
    }else{
        qWarning()<<"Tried to set "<<this->description<< "with wrong type or adress setting\n";
    }
}

// take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
void OscControlledFloatVector::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if((state1->getType()==this->getType())&&(state1->getAdress()==this->getAdress())&&
       (state2->getType()==this->getType())&&(state2->getAdress()==this->getAdress())
        ){
        QList<double> list1=state1->getAsDoubleList();
        QList<double> list2=state2->getAsDoubleList();
        QList<double> interpolated;
        if(list1.length()==this->numberOfComponents()&&list2.length()==this->numberOfComponents()){
            for (int i=0;i<this->numberOfComponents();i++){
                interpolated.push_back(list1.at(i)*fractionOf1+list2.at(i)*(1.0f-fractionOf1));
            }
            this->setValues(interpolated);
        }else{
            qWarning()<<"Tried to interpolate "<<this->description<< "with wrong number of float list entries\n";
        }
    }else{
        qWarning()<<"Tried to interpolate "<<this->description<< "with wrong type or adress setting\n";
    }
}


// equivalent to a copy constructor
OscControlledState* OscControlledFloatVector::getNewCopy(QObject* parent){
    return(new OscControlledFloatVector(this->adress,this->description,this->componentNames,this->currentValues,this->minValues,this->maxValues,parent));
}

QWidget* OscControlledFloatVector::makeUserControl(QWidget* parent){

        MultiSliderSettingWidget* guiWidget=new MultiSliderSettingWidget(this,parent);
        QObject::connect(this,SIGNAL(valuesChanged(QList<double>)),guiWidget,SLOT(updateGui()));
        return (guiWidget);


};

void OscControlledFloatVector::saveToFile(QFile* file){
    QString outString=
            QString("floatVector\t")+
            this->adress+"\t"+
            this->description+"\t"+
            QString::number(this->numberOfComponents());

    //write the component names
    for(int i=0;i<this->numberOfComponents();i++){
        outString.append("\t");
        outString.append(this->componentNames.at(i));
    }

    //write the current values
    for(int i=0;i<this->numberOfComponents();i++){
        outString.append("\t");
        outString.append(QString::number(this->currentValues.at(i)));
    }

    //write the min values
    for(int i=0;i<this->numberOfComponents();i++){
        outString.append("\t");
        outString.append(QString::number(this->minValues.at(i)));
    }

    //write the max values
    for(int i=0;i<this->numberOfComponents();i++){
        outString.append("\t");
        outString.append(QString::number(this->maxValues.at(i)));
    }
    outString.append("\n");
    file->write(outString.toStdString().c_str());
}
