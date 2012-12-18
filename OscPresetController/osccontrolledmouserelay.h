#ifndef OSCCONTROLLEDMOUSERELAY_H
#define OSCCONTROLLEDMOUSERELAY_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledMouseRelay : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledMouseRelay(
            QString adress,
            QString description,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            lastMouseX(0),
            lastMouseY(0),
            lastMouseButtons(0)
    {
}
    void setFromState(OscControlledState* source){}    ///< does nothing...
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){}   ///< does nothing...

    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    //getting type and value...
    OscStateType getType(){return OSC_STATE_MOUSE_RELAY;}
    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:
public slots:
    void receiveMouseData(double x, double y, int buttons); ///< update the internal mouse state copy and signal that it has changed
    void sendCurrentValue(QOscClient* oscClient);
private:
    double lastMouseX; //on a scale from 0 to 1
    double lastMouseY; //on a scale from 0 to 1
    int lastMouseButtons;   //1== left, 2==right 3==both
};

#endif // OscControlledMouseRelay_H
