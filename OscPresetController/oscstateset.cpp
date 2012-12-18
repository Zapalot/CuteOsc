#include "oscstateset.h"

OscStateSet::OscStateSet(QObject *parent) :
        QObject(parent)
{
}
void OscStateSet::loadFromFile(QString filename){
    //tidy up...
    qDeleteAll(this->stateList);
    this->stateList.clear();
    this->stateHash.clear();

    //set the name of the set...
    QStringList fileNameFragments=filename.split("/",QString::SkipEmptyParts);

    QString presetName=fileNameFragments.last();    //get the name without path
    int lastDot=presetName.lastIndexOf(".");
    if(lastDot!=-1){
        presetName.chop(presetName.length()-lastDot);  //chop of the file extension
    }
    this->name=presetName;
    emit this->nameChanged(this->name);

    //parse a list to preserve the initial order
    this->stateList= OscParameterDumpParser::parseFile(filename,this);

    //put all states into the hash for faster retrival
    QList<OscControlledState*>::iterator i;
    for (i = this->stateList.begin(); i != this->stateList.end(); ++i){
        this->stateHash.insert((*i)->getAdress(),(*i));
    }
}
void OscStateSet::saveToFile(QString filename){

    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))return;
    //save all states to a file...
    QList<OscControlledState*>::iterator i;
    for (i = this->stateList.begin(); i != this->stateList.end(); ++i){
        (*i)->saveToFile(&file);
    }
    file.close();
}


void OscStateSet::sendAll(QOscClient* client){
    //send all client states to the server
    QList<OscControlledState*>::iterator i;
    for (i = this->stateList.begin(); i != this->stateList.end(); ++i){
        (*i)->sendCurrentValue(client);
    }
}
// update all settings in the collection to the values of the "source" collection.
void OscStateSet::setFromSet(OscStateSet* source){
    QList<OscControlledState*> sourceStates=source->getStates();
    for(QList<OscControlledState*>::iterator i=sourceStates.begin();i!=sourceStates.end();i++){
        OscControlledState* targetState=this->stateHash.value((*i)->getAdress());
        if(targetState!=0){targetState->setFromState((*i));}
    }
}

// inspect the new set for states that do not exist in this set and add a new copy of them into this.
void OscStateSet::addNewStatesFromSet(OscStateSet* source){
    QList<OscControlledState*> sourceStates=source->getStates();
    for(QList<OscControlledState*>::iterator i=sourceStates.begin();i!=sourceStates.end();i++){
        OscControlledState* targetState=this->stateHash.value((*i)->getAdress());
        if(targetState==0){this->addState((*i)->getNewCopy(this));}
    }
}


// take a value between the two supplied state sets, the position (fractionOf1) is between 0 and 1
void OscStateSet::interpolateBetween(OscStateSet* stateSet1, OscStateSet* stateSet2, double fractionOf1){
    QList<OscControlledState*> sourceStates=stateSet1->getStates();

    for(QList<OscControlledState*>::iterator i=sourceStates.begin();i!=sourceStates.end();i++){
        OscControlledState* secondState=stateSet2->getState((*i)->getAdress());
        OscControlledState* targetState=this->stateHash.value((*i)->getAdress());
        if(secondState!=0&&targetState!=0){targetState->interpolateBetween((*i),secondState,fractionOf1);}
    }
}


// perform a deep copy of the colection, including all its states
OscStateSet* OscStateSet::getNewCopy(QObject* parent){
    OscStateSet* newCopy= new OscStateSet(parent);
    for(QList<OscControlledState*>::iterator i=this->stateList.begin();i!=this->stateList.end();i++){
        newCopy->addState((*i)->getNewCopy(newCopy));
    }
    newCopy->setName(this->getName());
    return(newCopy);
}
