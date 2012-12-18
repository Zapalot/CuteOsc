#ifndef OSCCONTROLLEDBOOL_H
#define OSCCONTROLLEDBOOL_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledBool : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledBool(
            QString adress,
            QString description,
            bool currentValue,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            currentValue(currentValue){}

    //getting type and value...
    void setFromState(OscControlledState* source);    ///< take the current value of another instance. checks for right key and type.
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    OscStateType getType(){return OSC_STATE_TYPE_BOOL;}
    double getAsDouble(){return(this->getAsInt());}
    int getAsInt(){return( this->currentValue?1:0);}
    bool getAsBool(){return( this->currentValue);}

    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:

public slots:
    void setValue(bool newValue){
        if(newValue!=this->currentValue){
            this->currentValue=newValue;
            this->changedSinceLastSend=true;
            emit this->valueChanged(this);
            emit this->valueChanged(QString(this->currentValue));
        }
    }

    void sendCurrentValue(QOscClient* oscClient){
        oscClient->sendData(this->adress,(int)this->getAsInt());
        this->changedSinceLastSend=false;
    }
private:
    bool currentValue;
};

#endif // OSCCONTROLLEDFLOAT_H
