#include "oscstatepreset.h"

OscStatePreset::OscStatePreset(OscStateSet* allStates,QObject *parent) :
    QObject(parent),
    allStates(allStates)
{
    this->presetStates= new OscStateSet(this);
    this->stateTreeModel= new QStandardItemModel(this);

    QStandardItemModel model;
    QStandardItem *parentItem = model.invisibleRootItem();
    for (int i = 0; i < 4; ++i) {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }


}

void OscStatePreset::updateStateModel(){

}
