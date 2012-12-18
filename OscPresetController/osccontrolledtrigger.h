#ifndef OSCCONTROLLEDTRIGGER_H
#define OSCCONTROLLEDTRIGGER_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledTrigger : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledTrigger(
            QString adress,
            QString description,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
    sendScheduled(false)
    {
}
    void setFromState(OscControlledState* source){}    ///< does nothing...
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){};   ///< does nothing...

    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    //getting type and value...
    OscStateType getType(){return OSC_STATE_TRIGGER;}
    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:
public slots:
    void triggered(){this->sendScheduled=true; emit this->valueChanged(this);emit this->valueChanged("bang");}
    void sendCurrentValue(QOscClient* oscClient){if(this->sendScheduled)oscClient->sendData(this->adress,"bang");this->sendScheduled=false;}
private:
    bool sendScheduled; //do we have to trigger on the next occasion?
};

#endif // OscControlledTrigger_H
