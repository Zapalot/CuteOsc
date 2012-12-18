#ifndef OSCCONTROLLEDSTATE_H
#define OSCCONTROLLEDSTATE_H

#include <QObject>
#include <QString>
#include <qoscclient.h>
#include <QWidget>
#include <QFile>

class OscControlledState : public QObject
{
    Q_OBJECT
public:

    enum OscStateType{
        OSC_STATE_TYPE_FLOAT,
        OSC_STATE_TYPE_INT,
        OSC_STATE_TYPE_ENUM,
        OSC_STATE_TYPE_BOOL,
        OSC_STATE_TRIGGER,   //not really a state, but useful i.e. for performing background updates
        OSC_STATE_TYPE_FLOAT_VECTOR,
        OSC_STATE_MOUSE_RELAY,   //not really a state, used to forward position and mouse buttonb information
        OSC_STATE_QUAD_2F,
        OSC_STATE_TYPE_STRING,
    };

    explicit OscControlledState(QString adress,QString description, QObject *parent = 0):
            QObject(parent),
            adress(adress),
            description(description),
            changedSinceLastSend(false){}

    virtual void setFromState(OscControlledState* source)=0;    ///< take the current value of another instance. must be implemented by derived classes. should check for right key and type.
    virtual void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1)=0;   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
    virtual OscControlledState* getNewCopy(QObject* parent=0)=0;   ///< equivalent to a copy constructor


    QString getAdress(){return(this->adress);}
    QString getDescription(){return(this->description);}
    virtual OscStateType getType()=0;
    virtual void saveToFile(QFile* file)=0;
    virtual QWidget* makeUserControl(QWidget* parent)=0;

    virtual double getAsDouble(){return 0;}
    virtual QList<double> getAsDoubleList(){return QList<double>();}
    virtual int  getAsInt(){return 0;}
    virtual bool getAsBool(){return false;}
    virtual QString getAsString(){return "";}
signals:
    void valueChanged(OscControlledState* state);   //can be used to implement an autoSend functionality
    void valueChanged(QString valueAsString);   // useful for updating labels
public slots:
    virtual void sendCurrentValue(QOscClient* oscClient)=0;
protected:

    QString adress;
    QString description;
    bool changedSinceLastSend;
};

#endif // OSCCONTROLLEDSTATE_H
