#ifndef TWOSTATEBLENDER_H
#define TWOSTATEBLENDER_H
#include "abstracttransition.h"
#include "oscstateset.h"
class TwoStateBlender : public AbstractTransition
{
    Q_OBJECT
public:
    explicit TwoStateBlender(OscStateSet* currentStateSet,  OscStateSet* outputStateSet, QObject *parent = 0);
    void setBlendState(OscStateSet* blendState, int index); ///< the stateSet given as a parameter is copied to the slot specified by index
    QWidget* makeUserControl(QWidget* parent);
signals:

public slots:
    void applyBlend(double fractionOf1);        ///< a mixture of blendStateSet1 and blendStateSet2 is set in the outputStateSet
    void setCurrentAsState1();                  ///< make a copy of the current state and use it as the first blend component
    void setCurrentAsState2();                  ///< make a copy of the current state and use it as the second blend component

    void loadState1(QString filename);          ///< load the first blend component from a file
    void loadState2(QString filename);          ///< load the second blend component from a file
private slots:
signals:
    void stateSet1NameChanged(QString newName);
    void stateSet2NameChanged(QString newName);
private:
    OscStateSet* currentStateSet;           ///< the current state of the controlled device. to fade from the current state and back
    OscStateSet* outputStateSet;            ///< all blends are written here

    OscStateSet* blendStateSet1;
    OscStateSet* blendStateSet2;
};

#endif // TWOSTATEBLENDER_H
