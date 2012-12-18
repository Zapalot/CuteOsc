#ifndef OSCCONTROLLEDSTRING_H
#define OSCCONTROLLEDSTRING_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledString : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledString(
            QString adress,
            QString description,
            QString currentValue,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            currentValue(currentValue){}

    //getting type and value...
    void setFromState(OscControlledState* source);    ///< take the current value of another instance. checks for right key and type.
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    OscStateType getType(){return OSC_STATE_TYPE_STRING;}
    virtual QString getAsString(){return this->currentValue;}
    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:

public slots:
    void setValue(QString newValue){
        if(newValue!=this->currentValue){
            this->currentValue=newValue;
            this->changedSinceLastSend=true;
            emit this->valueChanged(this);
            emit this->valueChanged(this->currentValue);
        }
    }

    void sendCurrentValue(QOscClient* oscClient){
        oscClient->sendData(this->adress,this->currentValue);
        this->changedSinceLastSend=false;
    }
private:
    QString currentValue;
};

#endif // OSCCONTROLLEDSTRING_H
