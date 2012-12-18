#include "vectorpadwidget.h"
#include "osccontrolledfloatvector.h"
#include <QDebug>
#include <QMouseEvent>
VectorPadWidget::VectorPadWidget(
        OscControlledFloatVector* setting,
        QWidget *parent ) :
        QWidget(parent),
        setting(setting)
{
    QList<QString> names=setting->getComponentNames();
    QGridLayout* layout = new QGridLayout(this);
    this->setLayout(layout);
}

void VectorPadWidget::updateGui(){
}


///<reimplement mouse move handling to capture moves...
void VectorPadWidget::mouseMoveEvent ( QMouseEvent * event ){
    if(event->buttons()&Qt::LeftButton){
        //calculate the relative mouse position on a scale from 0 to 1
        float xFract= (float)event->pos().x()/(float)this->width();
        float yFract= (float)event->pos().y()/(float)this->height();

        //send the new values to the setting
        QList<double> valueFractions;
        valueFractions.push_back(xFract);
        valueFractions.push_back(yFract);
        this->setting->setFromFractions(valueFractions);
    }
}
