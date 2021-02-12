/********************************************************************************
** Form generated from reading UI file 'twostateblenderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWOSTATEBLENDERWIDGET_H
#define UI_TWOSTATEBLENDERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TwoStateBlenderWidget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QPushButton *load1PushButton;
    QPushButton *setCurrentAs1PushButton;
    QPushButton *load2pushButton;
    QPushButton *setCurrentAs2PushButton;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;
    QLabel *state1Label;
    QLabel *state2Label;

    void setupUi(QWidget *TwoStateBlenderWidget)
    {
        if (TwoStateBlenderWidget->objectName().isEmpty())
            TwoStateBlenderWidget->setObjectName(QStringLiteral("TwoStateBlenderWidget"));
        TwoStateBlenderWidget->resize(455, 271);
        gridLayout = new QGridLayout(TwoStateBlenderWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(TwoStateBlenderWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        load1PushButton = new QPushButton(groupBox);
        load1PushButton->setObjectName(QStringLiteral("load1PushButton"));

        gridLayout_2->addWidget(load1PushButton, 0, 0, 1, 1);

        setCurrentAs1PushButton = new QPushButton(groupBox);
        setCurrentAs1PushButton->setObjectName(QStringLiteral("setCurrentAs1PushButton"));

        gridLayout_2->addWidget(setCurrentAs1PushButton, 1, 0, 1, 1);

        load2pushButton = new QPushButton(groupBox);
        load2pushButton->setObjectName(QStringLiteral("load2pushButton"));

        gridLayout_2->addWidget(load2pushButton, 0, 2, 1, 1);

        setCurrentAs2PushButton = new QPushButton(groupBox);
        setCurrentAs2PushButton->setObjectName(QStringLiteral("setCurrentAs2PushButton"));

        gridLayout_2->addWidget(setCurrentAs2PushButton, 1, 2, 1, 1);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setBaseSize(QSize(0, 0));
        horizontalSlider->setMaximum(128);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 3, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        state1Label = new QLabel(groupBox);
        state1Label->setObjectName(QStringLiteral("state1Label"));
        state1Label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(state1Label, 2, 0, 1, 1);

        state2Label = new QLabel(groupBox);
        state2Label->setObjectName(QStringLiteral("state2Label"));
        state2Label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        gridLayout_2->addWidget(state2Label, 2, 2, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);


        retranslateUi(TwoStateBlenderWidget);

        QMetaObject::connectSlotsByName(TwoStateBlenderWidget);
    } // setupUi

    void retranslateUi(QWidget *TwoStateBlenderWidget)
    {
        TwoStateBlenderWidget->setWindowTitle(QApplication::translate("TwoStateBlenderWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("TwoStateBlenderWidget", "GroupBox", Q_NULLPTR));
        load1PushButton->setText(QApplication::translate("TwoStateBlenderWidget", "Load", Q_NULLPTR));
        setCurrentAs1PushButton->setText(QApplication::translate("TwoStateBlenderWidget", "Current", Q_NULLPTR));
        load2pushButton->setText(QApplication::translate("TwoStateBlenderWidget", "Load", Q_NULLPTR));
        setCurrentAs2PushButton->setText(QApplication::translate("TwoStateBlenderWidget", "Current", Q_NULLPTR));
        state1Label->setText(QApplication::translate("TwoStateBlenderWidget", "TextLabel", Q_NULLPTR));
        state2Label->setText(QApplication::translate("TwoStateBlenderWidget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TwoStateBlenderWidget: public Ui_TwoStateBlenderWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWOSTATEBLENDERWIDGET_H
