#include "twostateblender.h"
#include "twostateblenderwidget.h"
TwoStateBlender::TwoStateBlender(OscStateSet* currentStateSet,  OscStateSet* outputStateSet,QObject *parent) :
    AbstractTransition(parent),
    currentStateSet(currentStateSet),
    outputStateSet(outputStateSet),
    blendStateSet1(new OscStateSet(this)),
    blendStateSet2(new OscStateSet(this))
{
}

// the stateSet given as a parameter is copied to the slot specified by index
void TwoStateBlender::setBlendState(OscStateSet* blendState, int index){
    if(index==0){
        delete this->blendStateSet1;
        this->blendStateSet1=blendState->getNewCopy(this);
        emit this->stateSet1NameChanged(this->blendStateSet1->getName());
    }
    if(index==1){
        delete this->blendStateSet2;
        this->blendStateSet2=blendState->getNewCopy(this);
        emit this->stateSet2NameChanged(this->blendStateSet2->getName());
    }

}

// a mixture of blendStateSet1 and blendStateSet2 is set in the outputStateSet
void TwoStateBlender::applyBlend(double fractionOf1){
    this->outputStateSet->interpolateBetween(this->blendStateSet1,this->blendStateSet2,fractionOf1);
}

void TwoStateBlender::setCurrentAsState1(){
    this->setBlendState(this->currentStateSet,0);
    this->blendStateSet1->setName("Current");
    emit this->stateSet1NameChanged(this->blendStateSet1->getName());
}

void TwoStateBlender::setCurrentAsState2(){
    this->setBlendState(this->currentStateSet,1);
    this->blendStateSet2->setName("Current");
    emit this->stateSet2NameChanged(this->blendStateSet2->getName());
}

// load the first blend component from a file
void TwoStateBlender::loadState1(QString filename){
    this->blendStateSet1->loadFromFile(filename);
    emit this->stateSet1NameChanged(this->blendStateSet1->getName());
}

// load the second blend component from a file
void TwoStateBlender::loadState2(QString filename){
    this->blendStateSet2->loadFromFile(filename);
    emit this->stateSet2NameChanged(this->blendStateSet2->getName());
}

QWidget* TwoStateBlender::makeUserControl(QWidget* parent){
   TwoStateBlenderWidget*  blenderWidget=new TwoStateBlenderWidget(this->blendStateSet1->getName(),this->blendStateSet2->getName(),parent);
   QObject::connect(blenderWidget,SIGNAL(fractionChanged(double)),this,SLOT(applyBlend(double)));
   QObject::connect(blenderWidget,SIGNAL(loadCurrentToOne()),this,SLOT(setCurrentAsState1()));
   QObject::connect(blenderWidget,SIGNAL(loadCurrentToTwo()),this,SLOT(setCurrentAsState2()));
   QObject::connect(blenderWidget,SIGNAL(loadFileToOne(QString)),this,SLOT(loadState1(QString)));
   QObject::connect(blenderWidget,SIGNAL(loadFileToTwo(QString)),this,SLOT(loadState2(QString)));
   QObject::connect(this,SIGNAL(stateSet1NameChanged(QString)),blenderWidget,SLOT(setOneName(QString)));
   QObject::connect(this,SIGNAL(stateSet2NameChanged(QString)),blenderWidget,SLOT(setTwoName(QString)));


   return(blenderWidget);
}
