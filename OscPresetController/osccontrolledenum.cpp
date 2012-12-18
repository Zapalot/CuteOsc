#include "osccontrolledenum.h"
#include <QDebug>
#include <QButtonGroup>
#include <QRadioButton>
#include <QVBoxLayout>

// take the current value of another instance. must be implemented by derived classes. checks for right key and type.
void OscControlledEnum::setFromState(OscControlledState* source){
    if((source->getType()==this->getType())&&source->getAdress()==this->getAdress()){
        this->currentValue=source->getAsInt();
    }else{
        qWarning()<<"Tried to set "<<this->description<< "with wrong type or adress setting\n";
    }
}

// take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
void OscControlledEnum::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if((state1->getType()==this->getType())&&(state1->getAdress()==this->getAdress())&&
       (state2->getType()==this->getType())&&(state2->getAdress()==this->getAdress())
        ){
        if(fractionOf1>=0.5){
            this->setValue(state1->getAsInt());
        }else{
            this->setValue(state2->getAsInt());
        }
    }
}

// equivalent to a copy constructor
OscControlledState* OscControlledEnum::getNewCopy(QObject* parent){
    return(new OscControlledEnum(this->adress,this->description,this->stateNames,this->currentValue,parent));
}

QWidget* OscControlledEnum::makeUserControl(QWidget* parent){




    QWidget* containerWidget=new QWidget(parent);
    QButtonGroup* buttonGroup=new QButtonGroup(parent);
    QVBoxLayout* layout = new QVBoxLayout(containerWidget);



    //make radiobutton for each state
    for(int i=0;i<this->stateNames.size();i++){
        QRadioButton* stateChoice= new QRadioButton(this->stateNames[i],parent);
        if(i==this->currentValue)stateChoice->setChecked(true);else stateChoice->setChecked(false);
        buttonGroup->addButton(stateChoice,i);
        layout->addWidget(stateChoice);
    }
    //put both into the container
    containerWidget->setLayout(layout);

    //update the values  on the sliders and labels upon changes
    QObject::connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(setValue(int)));

   // QObject::connect(this,SIGNAL(valueChanged(QString)),valueLabel,SLOT(setText(QString)));
    return (containerWidget);
};

void OscControlledEnum::saveToFile(QFile* file){
    QString outString=
            QString("enum")+"\t"+
            this->adress+"\t"+
            this->description+"\t"+
            QString::number(this->stateNames.size())+"\t";
    for(int i=0;i<this->stateNames.size();i++){
        outString+=this->stateNames[i];
        outString+="\t";
    }
    outString+=QString::number(this->currentValue);
    outString+="\n";

    file->write(outString.toStdString().c_str());
}
