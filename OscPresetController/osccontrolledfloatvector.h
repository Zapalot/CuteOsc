#ifndef OSCCONTROLLEDVEC3F_H
#define OSCCONTROLLEDVEC3F_H
#include <QObject>
#include <QPointer>
#include <QSlider>
#include <QLabel>
#include "osccontrolledstate.h"
#include <QList>
#include <QMultiMap>
#include <QDebug>


class OscControlledFloatVector : public OscControlledState
{
    Q_OBJECT
public:
    explicit OscControlledFloatVector(
            QString adress,
            QString description,
            QList<QString> componentNames,
            QList<double> currentValues,
            QList<double> minValues,
            QList<double> maxValues,
            QObject *parent = 0) :
            OscControlledState(adress,description, parent),
            componentNames(componentNames),
            currentValues(currentValues),
            minValues(minValues),
            maxValues(maxValues){}

    void setFromState(OscControlledState* source);    ///< take the current value of another instance. checks for right key and type ans size
    void interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1);   ///< take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
    OscControlledState* getNewCopy(QObject* parent=0);   ///< equivalent to a copy constructor

    OscStateType getType(){return OSC_STATE_TYPE_FLOAT_VECTOR;}             ///< get the content type
    virtual QWidget* makeUserControl(QWidget* parent);                      ///< make a gui
    QList<QString> getComponentNames(){return this->componentNames;}        ///< get the names of the vector components
    int numberOfComponents(){return this->currentValues.length();}          ///< number of vector components
    double getAsDouble(int index){return(this->currentValues.value(index));}  ///< get one of the components
    QList<double> getAsDoubleList(){return(this->currentValues);}            ///< get all components
    QList<double> getAsFractionList(){return(this->getFractionsFromValues(this->currentValues));}    ///< get all components as fractions between 0 and 1


    /// calculate the relative position of a set of values in the parameter range in a scale from 0-1(mainly for use with scrollbars as inputs)
    QList<double> getFractionsFromValues(QList<double> values){
        QList<double> fractions;
        if(values.length()!=this->currentValues.length()){qWarning()<<"Number of fractions does not match number of components in "<<this->adress;}
        for(int i =0; i< this->currentValues.length();i++){
            if(this->maxValues.value(i)!=this->minValues.value(i)){
                fractions.push_back((values.value(i)-this->minValues.value(i))/(this->maxValues.value(i)-this->minValues.value(i)));
            }else{
                fractions.push_back(0);
            }
        }
        return(fractions);
    }

    /// turn a set of relative parameter values on a 0-1 scale into the actual values of this setting
    QList<double> getValuesFromFractions(QList<double> fractions){
        QList<double> values;
        if(fractions.length()!=this->currentValues.length()){qWarning()<<"Number of fractions does not match number of components in "<<this->adress;}
        for(int i =0; i< this->currentValues.length();i++){
            values.push_back(this->minValues.value(i)+(this->maxValues.value(i)-this->minValues.value(i))*fractions[i]);
        }
        return(values);
    }
signals:
    void valuesChanged(QList<double> newValues);
public slots:
    void saveToFile(QFile* file);
    void setValue(double newValue, int index){
        if((index<= newValue)!=this->currentValues.length()&&this->currentValues.value(index)){
            this->currentValues[index]=newValue;
            this->changedSinceLastSend=true;
            emit this->valuesChanged(this->currentValues);
            emit this->valueChanged(this);
        }
    }
    void setValues(QList<double> newValues){
        bool anyChanges=false;
        if(newValues.length()==this->currentValues.length()){
            for(int i=0;i<newValues.length();i++){
                // cure constraint violoations
                if(newValues[i]<this->minValues[i])newValues[i]=this->minValues[i];
                if(newValues[i]>this->maxValues[i])newValues[i]=this->maxValues[i];
                if(newValues[i]!=this->currentValues[i]){
                    this->currentValues[i]=newValues[i];
                    anyChanges=true;
                }
            }
        }
        if(anyChanges){
            this->changedSinceLastSend=true;
            emit this->valuesChanged(this->currentValues);
            emit this->valueChanged(this);
        }
    }
    //sets the values from a 0-1 range, useful for sliders etc.
    void setFromFractions(QList<double> newFractions){
        this->setValues(this->getValuesFromFractions(newFractions));
    }


    void sendCurrentValue(QOscClient* oscClient){
        //the OSC send method takes only Qvariant lists, so we have to make one...
        QList<QVariant> sendArgs;
        for(int i=0;i<this->currentValues.length();i++){sendArgs.push_back(this->currentValues[i]);}
        oscClient->sendData(this->adress,sendArgs);
        this->changedSinceLastSend=false;
    }
protected slots:

protected:


    QList<QString> componentNames;
    QList<double> currentValues;
    QList<double> minValues;
    QList<double> maxValues;
};

#endif // OSCCONTROLLEDFLOAT_H
