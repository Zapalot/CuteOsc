#include "osctreenode.h"

OscGuiTreeNode::OscGuiTreeNode(QString adressFragment,QObject *parent) :
        QObject(parent),
        adressFragment(adressFragment),
        childNodeCount(0),
        maxBranchLength(0)
{
}

OscGuiTreeNode* OscGuiTreeNode::buildTreeFromStates(QHash<QString, OscControlledState*> oscStates,QObject* parent){
    OscGuiTreeNode* root = new OscGuiTreeNode("root",parent);
    QHash<QString, OscControlledState*>::iterator i;
    for (i = oscStates.begin(); i != oscStates.end(); ++i){
        root->attachOscState(i.value()->getAdress().split("/",QString::SkipEmptyParts),  i.value());
    }
    return(root);
}

//build a tree with all states supplied
OscGuiTreeNode* OscGuiTreeNode::buildTreeFromStates(OscStateSet* stateSet,QObject* parent){
    OscGuiTreeNode* root = new OscGuiTreeNode("root",parent);
    QList<OscControlledState*> allStates =stateSet->getStates();
    for (QList<OscControlledState*>::iterator i = allStates.begin(); i != allStates.end(); ++i){
        root->attachOscState((*i)->getAdress().split("/",QString::SkipEmptyParts),  (*i));
    }
    return(root);
}


void OscGuiTreeNode::attachOscState(QStringList remainingGuiPath, OscControlledState* newState){
    this->childNodeCount++;

    //keep track of the length of branches
    if(this->maxBranchLength<remainingGuiPath.length()){this->maxBranchLength=remainingGuiPath.length();}

    if(remainingGuiPath.length()>0){
        QString firstPathFragment=remainingGuiPath.first();
        //check if a node with the next gui adress part exists, else create one
        if(!this->childNodes.contains(firstPathFragment)){
            this->childNodes.insert(firstPathFragment, new OscGuiTreeNode(firstPathFragment,this));
        }

        //pass the state down the tree
        remainingGuiPath.pop_front();
        this->childNodes.value(firstPathFragment)->attachOscState(remainingGuiPath,newState);
    }else{
        //attach the state to this node
        this->oscStates.append(newState);
    }
}
//create a Gui that allows editing of all states below this node
QWidget* OscGuiTreeNode::createEditWidget( QWidget *parent){
    QWidget* containerWidget=0;
    switch(this->maxBranchLength){
    case(0):{
            //this is the end of a branch, it create only the control itself
            if(this->oscStates.length()>0){
                containerWidget=new QGroupBox(this->adressFragment,parent);
                QHBoxLayout *vbox = new QHBoxLayout;
                vbox->addWidget( this->oscStates.first()->makeUserControl(parent));
                containerWidget->setLayout(vbox);
            }
            break;}

    case(1):{
            //this is the last level of grouping, create a groupbox with all the controls
            containerWidget=new QGroupBox(this->adressFragment,parent);
            QHBoxLayout *vbox = new QHBoxLayout;
            QMap<QString, OscGuiTreeNode*>::iterator i;
            for (i = this->childNodes.begin(); i != this->childNodes.end(); ++i){
                vbox->addWidget(i.value()->createEditWidget(containerWidget));
            }
            containerWidget->setLayout(vbox);
            break;}
    case(2):{
            //this is the second-last level of grouping, create a page for the tabwidget with all the controls
            containerWidget=new QWidget(parent);
            QHBoxLayout *vbox = new QHBoxLayout;
            QMap<QString, OscGuiTreeNode*>::iterator i;
            for (i = this->childNodes.begin(); i != this->childNodes.end(); ++i){
                vbox->addWidget(i.value()->createEditWidget(containerWidget));
            }
            containerWidget->setLayout(vbox);
            break;}
    default:
        //this is a higher level, use a tab-widget for organizing the rest of the branch
        //this is the last level of grouping, create a groupbox with all the controls
        QTabWidget* tabWidget=new QTabWidget(parent);
        containerWidget=tabWidget;
        tabWidget->clear();
        QMap<QString, OscGuiTreeNode*>::iterator i;
        for (i = this->childNodes.begin(); i != this->childNodes.end(); ++i){
            tabWidget->addTab(i.value()->createEditWidget(containerWidget),i.value()->getGroupName());
        }

        break;
    }
    return(containerWidget);
}
