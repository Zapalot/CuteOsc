#ifndef OSCSTATESET_H
#define OSCSTATESET_H

#include <QObject>
#include <QHash>
#include <QList>
#include <QString>
#include <osccontrolledstate.h>
#include <oscparameterdumpparser.h>
#include <qoscclient.h>

class OscStateSet : public QObject
{
    Q_OBJECT
public:
    explicit OscStateSet(QObject *parent = 0);
    QString getName(){return this->name;}
    void setName(QString newName){this->name=newName;emit this->nameChanged(this->name);}

    void loadFromFile(QString filename);
    void saveToFile(QString filename);
    void sendAll(QOscClient* client);

    void setFromSet(OscStateSet* source);                   ///< update all settings in the collection to the values of the "source" collection.
    void addNewStatesFromSet(OscStateSet* source);          ///< inspect the new set for states that do not exist in this set and add a new copy of them into this.
    void interpolateBetween(OscStateSet* state1, OscStateSet* state2, double fractionOf1);   ///< take a value between the two supplied state sets, the position (fractionOf1) is between 0 and 1
    OscStateSet* getNewCopy(QObject* parent=0);     ///< perform a deep copy of the colection, including all its states

    /// adds a state to the collection and takes its ownership
    void addState(OscControlledState* newState){
        newState->setParent(this);
        this->stateList.append(newState);
        this->stateHash.insert(newState->getAdress(),newState);
    }

    /// deletes a state from the collection. if the state is owned (parent) by the collection, it is destroyed as well.
    void removeState(OscControlledState* stateToRemove){
        if(this->stateList.removeAll(stateToRemove)>0){
            this->stateHash.remove(stateToRemove->getAdress());
            if(stateToRemove->parent()==this){delete stateToRemove;}
        }
    }

    /// get a state instance by its name
    OscControlledState* getState(QString adress){
        return(this->stateHash.value(adress));
    }


    QList<OscControlledState*> getStates(){return this->stateList;}            ///< returns a shallow copy of all states in the collection
    QHash<QString, OscControlledState*> getStateHash(){return stateHash;}      ///< returns a shallow copy of all states in the collection

signals:
    void nameChanged(QString newName);
public slots:

protected:
    QString name;
    QList<OscControlledState*> stateList;
    QHash<QString, OscControlledState*> stateHash;

};

#endif // OSCSTATESET_H
