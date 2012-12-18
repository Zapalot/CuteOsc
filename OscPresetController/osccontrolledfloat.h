#ifndef OSCCONTROLLEDFLOAT_H
#define OSCCONTROLLEDFLOAT_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledFloat : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledFloat(
            QString adress,
            QString description,
            double currentValue,
            double minValue,
            double maxValue,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            currentValue(currentValue),
            minValue(minValue),
            maxValue(maxValue){}

    void setFromState(OscControlledState* source);    ///< take the current value of another instance. checks for right key and type.
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor


    //getting type and value...
    OscStateType getType(){return OSC_STATE_TYPE_FLOAT;}
    double getAsDouble(){return(this->currentValue);}
    int getAsInt(){return((this->currentValue-this->minValue)/(this->maxValue-this->minValue)*1024.0f);}


    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:

public slots:
    void setValue(double newValue){
        if(newValue!=this->currentValue){
            this->currentValue=newValue;
            this->changedSinceLastSend=true;
            emit this->valueChanged(this);
            emit this->valueChanged(QString::number(this->currentValue,'f',2));
        }
    }
    void setValueFromInt(int sliderInt){
        if(sliderInt!= this->getAsInt()){
            this->setValue(this->minValue+(this->maxValue-this->minValue)*((double)sliderInt)/1024.0f);
        }
    }
    void sendCurrentValue(QOscClient* oscClient){
        oscClient->sendData(this->adress,(double)this->currentValue);
        this->changedSinceLastSend=false;
    }
private:
    double currentValue;
    double minValue; double maxValue;
};

#endif // OSCCONTROLLEDFLOAT_H
