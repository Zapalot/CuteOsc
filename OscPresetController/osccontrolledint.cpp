#include "osccontrolledint.h"
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QDebug>

// take the current value of another instance. must be implemented by derived classes. checks for right key and type.
void OscControlledInt::setFromState(OscControlledState* source){
    if((source->getType()==this->getType())&&source->getAdress()==this->getAdress()){
        this->currentValue=source->getAsDouble();
    }else{
        qWarning()<<"Tried to set "<<this->description<< "with wrong type or adress setting\n";
    }
}

// take a value between the two supplied states, the position (fractionOf1) is between 0 and 1
void OscControlledInt::interpolateBetween(OscControlledState* state1, OscControlledState* state2, double fractionOf1){
    if((state1->getType()==this->getType())&&(state1->getAdress()==this->getAdress())&&
       (state2->getType()==this->getType())&&(state2->getAdress()==this->getAdress())
        ){
        this->setValue((int)(state1->getAsDouble()*fractionOf1+state2->getAsDouble()*(1.0f-fractionOf1)));
    }
}

// equivalent to a copy constructor
OscControlledState* OscControlledInt::getNewCopy(QObject* parent){
    return(new OscControlledInt(this->adress,this->description,this->currentValue,this->minValue,this->maxValue,parent));
}

QWidget* OscControlledInt::makeUserControl(QWidget* parent){
    QWidget* containerWidget=new QWidget(parent);
    QVBoxLayout* layout = new QVBoxLayout(containerWidget);

    //make a slider to set the values
    QSlider* slider = new QSlider(Qt::Vertical,parent);
    slider->setMinimum(this->minValue);
    slider->setMaximum(this->maxValue);
    int newVal=this->getAsInt();
    slider->setValue(newVal);

    layout->addWidget(slider);

    //and a label to display values
    QLabel* valueLabel= new QLabel(QString::number(this->currentValue),containerWidget);
    layout->addWidget(valueLabel);


    //put both into the container
    containerWidget->setLayout(layout);

    //update the values  on the sliders and labels upon changes
    QObject::connect(slider,SIGNAL(valueChanged(int)),this,SLOT(setValue(int)));
    QObject::connect(this,SIGNAL(valueChanged(QString)),valueLabel,SLOT(setText(QString)));
    return (containerWidget);
};

void OscControlledInt::saveToFile(QFile* file){
    QString outString=
            QString("int")+"\t"+
            this->adress+"\t"+
            this->description+"\t"+
            QString::number(this->currentValue)+"\t"+
            QString::number(this->minValue)+"\t"+
            QString::number(this->maxValue)+"\n";
    file->write(outString.toStdString().c_str());
}
