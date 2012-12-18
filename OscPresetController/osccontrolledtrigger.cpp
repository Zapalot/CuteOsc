#include "osccontrolledtrigger.h"
#include <QPushButton>

// equivalent to a copy constructor
OscControlledState* OscControlledTrigger::getNewCopy(QObject* parent){
    return (new OscControlledTrigger(this->adress,this->description,parent));
}


QWidget* OscControlledTrigger::makeUserControl(QWidget* parent){
    QPushButton* triggerButton=new QPushButton(this->description,parent);
    QObject::connect(triggerButton,SIGNAL(clicked()),this,SLOT(triggered()));
    return (triggerButton);
};

void OscControlledTrigger::saveToFile(QFile* file){
    QString outString=
            QString("trigger\t")+
            this->adress+"\t"+
            this->description+"\n";
    file->write(outString.toStdString().c_str());
}
