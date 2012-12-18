#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHash>
#include <QFileDialog>
#include <QSettings>
#include <QHostAddress>


#include "oscparameterdumpparser.h"
#include "osccontrolledstate.h"
#include "oscstateset.h"
#include "osctreenode.h"
#include "qoscclient.h"
#include <QDockWidget>
#include "twostateblender.h"
#include "twostateblenderwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSettings* appSettings;
    OscGuiTreeNode* guiTreeRoot;
    OscStateSet* displayedStates;

    QWidget* settingsDisplay;
    QOscClient* oscClient;

    QTimer* loadAndQuitTimer;
    QString loadAndQuitFilename;


private slots:
    void on_actionSendCurrent_triggered();
    void loadAndQuit(); ///< loads a parameter set and terminates the application
    void on_actionNew_Blender_triggered();
    void on_actionSave_OSC_Parameters_triggered();
    void on_actionSet_Port_triggered();
    void on_actionSet_IP_triggered();
    void updateState(OscControlledState* state);
    void on_actionLoad_OSC_Parameters_triggered();
};

#endif // MAINWINDOW_H
