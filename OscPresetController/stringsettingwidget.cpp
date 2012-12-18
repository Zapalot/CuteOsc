#include "stringsettingwidget.h"
#include "osccontrolledfloatvector.h"
#include <QDebug>
StringSettingWidget::StringSettingWidget(
        OscControlledString* setting,
        QWidget *parent ) :
        QWidget(parent),
        setting(setting)
{



    QGridLayout* layout = new QGridLayout(this);
    this->button=new QPushButton(setting->getAsString(),parent);
    layout->addWidget(this->button,0,0);


    //receive movements of the slider and update the whole thing...
    QObject::connect(this->button,SIGNAL(pressed()),this,SLOT(buttonPressed()));
    QObject::connect(this->setting,SIGNAL(valueChanged(QString)),this,SLOT(updateGui()));

    this->setLayout(layout);
}

void StringSettingWidget::updateGui(){
    this->button->setText(this->setting->getAsString());
}

void StringSettingWidget::buttonPressed(){

    this->setting->setValue(QInputDialog::getText(this,"Enter new "+ this->setting->getDescription(),this->setting->getDescription()+" :",QLineEdit::Normal,this->setting->getAsString()));
}
