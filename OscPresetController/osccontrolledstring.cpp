#include "osccontrolledstring.h"
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QDebug>
#include "stringsettingwidget.h"
// take the current value of another instance. must be implemented by derived classes. checks for right key and type.
void OscControlledString::setFromState(OscControlledState* source){
    if((source->getType()==this->getType())&&source->getAdress()==this->getAdress()){
        this->setValue(source->getAsString());
    }else{
        qWarning()<<"Tried to set "<<this->description<< "with wrong type or adress setting\n";
    }
}

/// take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
void OscControlledString::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if((state1->getType()==this->getType())&&(state1->getAdress()==this->getAdress())&&
       (state2->getType()==this->getType())&&(state2->getAdress()==this->getAdress())
        ){
        if(fractionOf1>0.5f){this->setValue(state1->getAsString());}else{this->setValue(state2->getAsString());}
    }
}

// equivalent to a copy constructor
OscControlledState* OscControlledString::getNewCopy(QObject* parent){
    return(new OscControlledString(this->adress,this->description,this->currentValue,parent));
}


QWidget* OscControlledString::makeUserControl(QWidget* parent){

    return (new StringSettingWidget(this,parent));
};

void OscControlledString::saveToFile(QFile* file){
    QString outString=
            QString("string")+"\t"+
            this->adress+"\t"+
            this->description+"\t"+
            this->currentValue+"\n";
    file->write(outString.toStdString().c_str());
}
