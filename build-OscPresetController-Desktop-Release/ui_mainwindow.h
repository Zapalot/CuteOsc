/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad_OSC_Parameters;
    QAction *actionSet_IP;
    QAction *actionSet_Port;
    QAction *actionSave_OSC_Parameters;
    QAction *actionNew_Blender;
    QAction *actionSendCurrent;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QDockWidget *stateControlDockWidget;
    QWidget *stateControlDockWidgetContents;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QMenu *menuTransitions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(991, 436);
        actionLoad_OSC_Parameters = new QAction(MainWindow);
        actionLoad_OSC_Parameters->setObjectName(QStringLiteral("actionLoad_OSC_Parameters"));
        actionSet_IP = new QAction(MainWindow);
        actionSet_IP->setObjectName(QStringLiteral("actionSet_IP"));
        actionSet_Port = new QAction(MainWindow);
        actionSet_Port->setObjectName(QStringLiteral("actionSet_Port"));
        actionSave_OSC_Parameters = new QAction(MainWindow);
        actionSave_OSC_Parameters->setObjectName(QStringLiteral("actionSave_OSC_Parameters"));
        actionNew_Blender = new QAction(MainWindow);
        actionNew_Blender->setObjectName(QStringLiteral("actionNew_Blender"));
        actionSendCurrent = new QAction(MainWindow);
        actionSendCurrent->setObjectName(QStringLiteral("actionSendCurrent"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        stateControlDockWidget = new QDockWidget(MainWindow);
        stateControlDockWidget->setObjectName(QStringLiteral("stateControlDockWidget"));
        stateControlDockWidgetContents = new QWidget();
        stateControlDockWidgetContents->setObjectName(QStringLiteral("stateControlDockWidgetContents"));
        gridLayout = new QGridLayout(stateControlDockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        stateControlDockWidget->setWidget(stateControlDockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), stateControlDockWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 991, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuTransitions = new QMenu(menuBar);
        menuTransitions->setObjectName(QStringLiteral("menuTransitions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuBar->addAction(menuTransitions->menuAction());
        menuFile->addAction(actionLoad_OSC_Parameters);
        menuFile->addAction(actionSave_OSC_Parameters);
        menuFile->addSeparator();
        menuFile->addAction(actionSendCurrent);
        menuSettings->addAction(actionSet_IP);
        menuSettings->addAction(actionSet_Port);
        menuTransitions->addAction(actionNew_Blender);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionLoad_OSC_Parameters->setText(QApplication::translate("MainWindow", "Load Parameter Set", Q_NULLPTR));
        actionSet_IP->setText(QApplication::translate("MainWindow", "Set IP", Q_NULLPTR));
        actionSet_Port->setText(QApplication::translate("MainWindow", "Set Port", Q_NULLPTR));
        actionSave_OSC_Parameters->setText(QApplication::translate("MainWindow", "Save Parameter Set", Q_NULLPTR));
        actionNew_Blender->setText(QApplication::translate("MainWindow", "New Blender", Q_NULLPTR));
        actionSendCurrent->setText(QApplication::translate("MainWindow", "SendCurrent", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        stateControlDockWidget->setWhatsThis(QApplication::translate("MainWindow", "Current Set", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        stateControlDockWidget->setWindowTitle(QApplication::translate("MainWindow", "State Control", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
        menuTransitions->setTitle(QApplication::translate("MainWindow", "Transitions", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
