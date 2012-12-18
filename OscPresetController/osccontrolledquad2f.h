#ifndef OSCCONTROLLEDQUAD2F_H
#define OSCCONTROLLEDQUAD2F_H
#include <QObject>
#include "osccontrolledstate.h"
class OscControlledQuad2f : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledQuad2f(
            QString adress,
            QString description,
            QPointF minValue,
            QPointF maxValue,
            QPointF corners[4],
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            minValue(minValue),
            maxValue(maxValue)
    {
        for (int i=0;i<4;i++){
            this->corners[i]=corners[i];
        }
}
    void setFromState(OscControlledState* source);
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);
    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    //getting type and value...
    OscStateType getType(){return OSC_STATE_QUAD_2F;}
    QPointF* getCorners(){return this->corners;}
    QPointF getMinValue(){return this->minValue;}
    QPointF getMaxValue(){return this->maxValue;}
    virtual QWidget* makeUserControl(QWidget* parent);
    void saveToFile(QFile* file);
signals:
public slots:
    void sendCurrentValue(QOscClient* oscClient);
private:

    QPointF minValue;
    QPointF maxValue;
    QPointF corners[4];
};

#endif // OscControlledQuad2f_H
