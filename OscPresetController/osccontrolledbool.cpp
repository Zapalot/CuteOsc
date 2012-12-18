#include "osccontrolledbool.h"
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>
#include <QDebug>
// take the current value of another instance. must be implemented by derived classes. checks for right key and type.
void OscControlledBool::setFromState(OscControlledState* source){
    if((source->getType()==this->getType())&&source->getAdress()==this->getAdress()){
        this->setValue(source->getAsBool());
    }else{
        qWarning()<<"Tried to set "<<this->description<< "with wrong type or adress setting\n";
    }
}

/// take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
void OscControlledBool::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if((state1->getType()==this->getType())&&(state1->getAdress()==this->getAdress())&&
       (state2->getType()==this->getType())&&(state2->getAdress()==this->getAdress())
        ){
        if(fractionOf1>0.5f){this->setValue(state1->getAsBool());}else{this->setValue(state2->getAsBool());}
    }
}

// equivalent to a copy constructor
OscControlledState* OscControlledBool::getNewCopy(QObject* parent){
    return(new OscControlledBool(this->adress,this->description,this->currentValue,parent));
}


QWidget* OscControlledBool::makeUserControl(QWidget* parent){
    QCheckBox* checkbox= new QCheckBox(this->description,parent);
    checkbox->setChecked(this->currentValue);
    //update the values  on the sliders and labels upon changes
    QObject::connect(checkbox,SIGNAL(toggled(bool)),this,SLOT(setValue(bool)));
    return (checkbox);
};

void OscControlledBool::saveToFile(QFile* file){
    QString outString=
            QString("bool")+"\t"+
            this->adress+"\t"+
            this->description+"\t"+
            (this->currentValue?"1":"0")+"\n";
    file->write(outString.toStdString().c_str());
}
