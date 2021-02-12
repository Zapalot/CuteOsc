/********************************************************************************
** Form generated from reading UI file 'playground.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYGROUND_H
#define UI_PLAYGROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Playground
{
public:
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QWidget *Playground)
    {
        if (Playground->objectName().isEmpty())
            Playground->setObjectName(QStringLiteral("Playground"));
        Playground->resize(400, 300);
        radioButton = new QRadioButton(Playground);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(130, 50, 82, 17));
        radioButton_2 = new QRadioButton(Playground);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(100, 70, 82, 17));

        retranslateUi(Playground);

        QMetaObject::connectSlotsByName(Playground);
    } // setupUi

    void retranslateUi(QWidget *Playground)
    {
        Playground->setWindowTitle(QApplication::translate("Playground", "Form", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Playground", "RadioButton", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Playground", "RadioButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Playground: public Ui_Playground {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYGROUND_H
