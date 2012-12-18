#include "multislidersettingwidget.h"
#include "osccontrolledfloatvector.h"
#include <QDebug>
MultiSliderSettingWidget::MultiSliderSettingWidget(
        OscControlledFloatVector* setting,
        QWidget *parent ) :
        QWidget(parent),
        setting(setting)
{
    QList<QString> names=setting->getComponentNames();
    QList<double> values=setting->getAsDoubleList();
    QList<double> valueFractions=setting->getAsFractionList();


    QGridLayout* layout = new QGridLayout(this);
    for (int i =0;i<setting->numberOfComponents();i++){
        //and a label to display the name of the component
        QLabel* nameLabel= new QLabel(names[i],this);
        layout->addWidget(nameLabel,0,i);

        //make a slider to set the values
        QSlider* slider = new QSlider(Qt::Vertical,parent);
        this->sliders.push_back(slider);
        slider->setMinimum(0);
        slider->setMaximum(1024);
        slider->setValue(valueFractions[i]*1024.0f);
        layout->addWidget(slider,1,i);

        //receive movements of the slider and update the whole thing...
        QObject::connect(slider,SIGNAL(valueChanged(int)),this,SLOT(sliderMoved()));

        //and a label to display values
        QLabel* valueLabel= new QLabel(QString::number(values[i],'f',2),this);
        this->labels.push_back(valueLabel);
        layout->addWidget(valueLabel,2,i);
    }

    this->setLayout(layout);
}

void MultiSliderSettingWidget::updateGui(){
    QList<double> values=this->setting->getAsDoubleList();
    QList<double> valueFractions=this->setting->getAsFractionList();
    if(values.length()!=this->sliders.length()){
        qWarning()<< "Trying to set sliders with incompatible number of values!";
    }else{
        for (int i =0;i<this->sliders.length();i++){
            //update only if their position has really changed to prevent an inifinite loop of updates
            int sliderValue=valueFractions[i]*1024.0f;
            if(this->sliders[i]->value()!=sliderValue){
                this->sliders[i]->setValue(valueFractions[i]*1024.0f);
            }
            this->labels[i]->setText(QString::number(values[i],'f',2));
        }
    }
}

void MultiSliderSettingWidget::sliderMoved(){
    QList<double> valueFractions;
    for (int i =0;i<this->sliders.length();i++){
        valueFractions.push_back(((double)this->sliders[i]->value())/1024.0f);
    }
    this->setting->setFromFractions(valueFractions);
}
