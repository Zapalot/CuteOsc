#ifndef STRINGSETTINGWIDGET_H
#define STRINGSETTINGWIDGET_H

#include <QWidget>

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QInputDialog>
#include <QList>
#include <QString>

#include "osccontrolledstring.h"

class StringSettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StringSettingWidget(
            OscControlledString* setting,
            QWidget *parent = 0);

signals:
public slots:
    void updateGui();  // update the values in the gui using the internal setting reference
private slots:
    void buttonPressed();
private:
    OscControlledString* setting;
    QPushButton* button;
    QLabel* label;

};

#endif // STRINGSETTINGWIDGET_H
