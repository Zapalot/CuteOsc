#ifndef MULTISLIDERSETTINGWIDGET_H
#define MULTISLIDERSETTINGWIDGET_H

#include <QWidget>

#include <QGridLayout>
#include <QSlider>
#include <QLabel>

#include <QList>
#include <QString>

class OscControlledFloatVector; //prototype it here ao we can use it to initialize in the constructor

class MultiSliderSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MultiSliderSettingWidget(
            OscControlledFloatVector* setting,
            QWidget *parent = 0);

signals:
public slots:
    void updateGui();  // update the values in the gui using the internal setting reference
private slots:
    void sliderMoved();
private:
    OscControlledFloatVector* setting;
    QList<QSlider*> sliders;
    QList<QLabel*> labels;
};

#endif // MULTISLIDERSETTINGWIDGET_H
