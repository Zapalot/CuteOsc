#include "mouserelaywidget.h"
#include <QMouseEvent>
MouseRelayWidget::MouseRelayWidget(QWidget *parent) :
        QWidget(parent)
{
    this->setMouseTracking(true);   //receive mouse events even if no button is pressed
}

// reimplement mouse move handling to capture moves...
void MouseRelayWidget::mouseMoveEvent ( QMouseEvent * event ){
    //calculate the relative mouse position on a scale from 0 to 1
    float xFract= (float)event->pos().x()/(float)this->width();
    float yFract= (float)event->pos().y()/(float)this->height();
    emit this->mouseSignal(xFract,yFract,event->buttons());
    event->accept();
}

void MouseRelayWidget::mousePressEvent ( QMouseEvent * event ){
    //calculate the relative mouse position on a scale from 0 to 1
    float xFract= (float)event->pos().x()/(float)this->width();
    float yFract= (float)event->pos().y()/(float)this->height();
    emit this->mouseSignal(xFract,yFract,event->buttons());
    event->accept();
}
void MouseRelayWidget::mouseReleaseEvent ( QMouseEvent * event ){
    //calculate the relative mouse position on a scale from 0 to 1
    float xFract= (float)event->pos().x()/(float)this->width();
    float yFract= (float)event->pos().y()/(float)this->height();
    emit this->mouseSignal(xFract,yFract,event->buttons());
    event->accept();
}
