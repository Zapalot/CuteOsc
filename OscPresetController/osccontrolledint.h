#ifndef OSCCONTROLLEDINT_H
#define OSCCONTROLLEDINT_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledInt : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledInt(
            QString adress,
            QString description,
            int currentValue,
            int minValue,
            int maxValue,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            currentValue(currentValue),
            minValue(minValue),
            maxValue(maxValue){}

    void setFromState(OscControlledState* source);    ///< take the current value of another instance. checks for right key and type.
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1

    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    //getting type and value...
    OscStateType getType(){return OSC_STATE_TYPE_INT;}
    double getAsDouble(){return(this->currentValue);}
    int getAsInt(){return(this->currentValue);}


    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:

public slots:
    void setValue(int newValue){
        if(newValue!=this->currentValue){
            this->currentValue=newValue;
            this->changedSinceLastSend=true;
            emit this->valueChanged(this);
            emit this->valueChanged(QString::number(this->currentValue));
        }
    }

    void sendCurrentValue(QOscClient* oscClient){
        oscClient->sendData(this->adress,(int)this->currentValue);
        this->changedSinceLastSend=false;
    }
private:
    int currentValue;
    int minValue; int maxValue;
};

#endif // OSCCONTROLLEDFLOAT_H
