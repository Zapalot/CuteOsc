#include "osccontrolledmouserelay.h"
#include <QPushButton>
#include "mouserelaywidget.h"
// equivalent to a copy constructor
OscControlledState* OscControlledMouseRelay::getNewCopy(QObject* parent){
    return (new OscControlledMouseRelay(this->adress,this->description,parent));
}


QWidget* OscControlledMouseRelay::makeUserControl(QWidget* parent){
    MouseRelayWidget* theWidget= new MouseRelayWidget(parent);
    QObject::connect(theWidget,SIGNAL(mouseSignal(double,double,int)),this,SLOT(receiveMouseData(double,double,int)));
    return (theWidget);
};

void OscControlledMouseRelay::saveToFile(QFile* file){
    QString outString=
            QString("mouseRelay\t")+
            this->adress+"\t"+
            this->description+"\n";
    file->write(outString.toStdString().c_str());
}

void OscControlledMouseRelay::receiveMouseData(double x, double y, int buttons){
    this->lastMouseX=x;
    this->lastMouseY=y;
    this->lastMouseButtons=buttons;
    this->changedSinceLastSend=true;
    emit this->valueChanged(this);
}

void OscControlledMouseRelay::sendCurrentValue(QOscClient* oscClient){
    QList<QVariant> sendData;
    sendData.push_back(this->lastMouseX);
    sendData.push_back(this->lastMouseY);
    sendData.push_back(this->lastMouseButtons);
    oscClient->sendData(this->adress,sendData);
}
