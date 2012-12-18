#ifndef VECTORPADWIDGET_H
#define VECTORPADWIDGET_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>

#include <QList>
#include <QString>

class OscControlledFloatVector; //prototype it here ao we can use it to initialize in the constructor

class VectorPadWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VectorPadWidget(
            OscControlledFloatVector* setting,
            QWidget *parent = 0);

signals:
public slots:
    void updateGui();  // update the values in the gui using the internal setting reference
private:
    void mouseMoveEvent ( QMouseEvent * event ); ///<reimplement mouse move handling to capture moves...
    OscControlledFloatVector* setting;
};

#endif // VECTORPADWIDGET_H
