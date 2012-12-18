#ifndef OSCTREENODE_H
#define OSCTREENODE_H

#include <QObject>
#include <QHash>
#include <QMap>
#include <osccontrolledstate.h>
#include <oscstateset.h>
#include <QWidget>
#include <QGroupBox>
#include <QTabWidget>
#include <QHBoxLayout>

class OscGuiTreeNode : public QObject
{
    Q_OBJECT
public:
    explicit OscGuiTreeNode(QString adressFragment, QObject *parent = 0);
    void attachOscState(QStringList remainingGuiPath,OscControlledState* newState);  //attaches a new state by recursively building a branch in the tree structure
    QWidget* createEditWidget( QWidget *parent = 0);    //create a Gui that allows editing of all states below this node

    QString getGroupName(){return(this->adressFragment);}
    static OscGuiTreeNode* buildTreeFromStates(QHash<QString, OscControlledState*> oscStates,QObject* parent); //build a tree with all states supplied
    static OscGuiTreeNode* buildTreeFromStates(OscStateSet* stateSet,QObject* parent); //build a tree with all states supplied


signals:

public slots:
protected:

    QString adressFragment;
    QMap<QString, OscGuiTreeNode*> childNodes;
    QList<OscControlledState*> oscStates;
    int childNodeCount;
    int maxBranchLength;

};

#endif // OSCTREENODE_H
