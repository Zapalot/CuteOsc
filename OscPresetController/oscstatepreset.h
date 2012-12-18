#ifndef OSCSTATEPRESET_H
#define OSCSTATEPRESET_H

#include <QObject>
#include <QStandardItemModel>
#include "oscstateset.h"



/// contains a set of osc parameters and additional information specific to working with osc state presets
/// as a specific addition, it maintains a subset of "active" parameters.
class OscStatePreset : public QObject
{
    Q_OBJECT
public:
    explicit OscStatePreset( OscStateSet* allStates, QObject *parent = 0);
    void loadFromFile(QString filename){this->presetStates->loadFromFile(filename);this->updateStateModel();}
    OscStateSet* getPresetStates(){return this->presetStates;}

signals:

public slots:
private slots:
    void updateStateModel();
protected:
    QStandardItemModel* stateTreeModel;
    OscStateSet* allStates;     ///< contains all states that can be selected as part of this preset. not owned by the preset, not deleted at the end of its life
    OscStateSet* presetStates;  ///< containes the states of the preset with their current values.
};

#endif // OSCSTATEPRESET_H
