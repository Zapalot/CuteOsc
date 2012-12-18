#include "osccontrolledquad2f.h"
#include <QPushButton>
#include "mouserelaywidget.h"
// equivalent to a copy constructor
OscControlledState* OscControlledQuad2f::getNewCopy(QObject* parent){
    return (new OscControlledQuad2f(
            this->adress,
            this->description,
            this->minValue,
            this->maxValue,
            this->corners,
            parent));
}


QWidget* OscControlledQuad2f::makeUserControl(QWidget* parent){
    // MouseRelayWidget* theWidget= new MouseRelayWidget(parent);
    //QObject::connect(theWidget,SIGNAL(mouseSignal(double,double,int)),this,SLOT(receiveMouseData(double,double,int)));
    return (new QWidget(parent));
};

void OscControlledQuad2f::saveToFile(QFile* file){
    QString outString=
            QString("quad2f\t")+
            this->adress+"\t"+
            this->description+"\t"+
            QString::number(this->minValue.x())+"\t"+
            QString::number(this->minValue.y())+"\t"+
            QString::number(this->maxValue.x())+"\t"+
            QString::number(this->maxValue.y());
    for(int i=0;i<4;i++){
        outString+="\t";
        outString+=QString::number(this->corners[i].x());
        outString+="\t";
        outString+=QString::number(this->corners[i].y());
    }
    outString+="\n";
    file->write(outString.toStdString().c_str());
}



void OscControlledQuad2f::sendCurrentValue(QOscClient* oscClient){
    QList<QVariant> sendData;
    for(int i=0;i<4;i++){
        sendData.push_back((double)this->corners[i].x());
        sendData.push_back((double)this->corners[i].y());
    }
    oscClient->sendData(this->adress,sendData);
}

void OscControlledQuad2f::setFromState(OscControlledState* source){
    if(source->getType()==OSC_STATE_QUAD_2F){
        OscControlledQuad2f* castedSource=dynamic_cast<OscControlledQuad2f*>(source);
        this->minValue=castedSource->getMinValue();
        this->minValue=castedSource->getMaxValue();
        for(int i=0;i<4;i++){
            this->corners[i]=castedSource->getCorners()[i];
        }
    }
}

void OscControlledQuad2f::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if(state1->getType()==OSC_STATE_QUAD_2F&&state2->getType()==OSC_STATE_QUAD_2F){
        OscControlledQuad2f* castedState1=dynamic_cast<OscControlledQuad2f*>(state1);
        OscControlledQuad2f* castedState2=dynamic_cast<OscControlledQuad2f*>(state2);
        for(int i=0;i<4;i++){
            this->corners[i]=castedState1->getCorners()[i]*fractionOf1+(1.0-fractionOf1)*castedState2->getCorners()[i];
        }
    }
}
