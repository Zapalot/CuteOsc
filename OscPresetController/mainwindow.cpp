#include "mainwindow.h"
#include "ui_mainwindow.h"
#include  <QSlider>
#include <QHostAddress>
#include <QInputDialog>
#include <QIODevice>
#include <QTimer>
#include <QStringList>
MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        appSettings(new QSettings("Homebrew","OscController",this)),
        guiTreeRoot(0),
        displayedStates(0),
        settingsDisplay(0)
{
    ui->setupUi(this);
    this->oscClient=new QOscClient(QHostAddress(
            this->appSettings->value("targetIp","127.0.0.1").toString()),
                                   this->appSettings->value("targetPort",8000).toInt(),
                                   this);
    this->displayedStates = new OscStateSet(this);

    QStringList arguments=QCoreApplication::arguments();
    if(arguments.size()==4){
        if (arguments[1]=="loadAndQuit"){
            this->loadAndQuitFilename=arguments[2];
            float startDelay=arguments[3].toFloat();
            if(startDelay!=0){
                this->loadAndQuitTimer= new QTimer(this);
                QObject::connect(this->loadAndQuitTimer,SIGNAL(timeout()),this,SLOT(loadAndQuit()));
                this->loadAndQuitTimer->start(startDelay);
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLoad_OSC_Parameters_triggered()
{

    QString filename=QFileDialog::getOpenFileName(this,
                                                  "Choose preset",this->appSettings->value("lastFile","").toString(),
                                                  "*.txt"
                                                  );
    if(filename!=""){
        if(this->displayedStates!=0){delete this->displayedStates;this->displayedStates = new OscStateSet(this);};
        if(this->guiTreeRoot!=0){delete this->guiTreeRoot;};

        if(this->settingsDisplay!=0){
            this->ui->stateControlDockWidgetContents->layout()->removeWidget(this->settingsDisplay);
            delete this->settingsDisplay;
        };


        this->appSettings->setValue("lastFile",filename);
        this->displayedStates->loadFromFile(filename);
        this->guiTreeRoot=OscGuiTreeNode::buildTreeFromStates(this->displayedStates,this);
        this->settingsDisplay=this->guiTreeRoot->createEditWidget(this);
        this->ui->stateControlDockWidgetContents->layout()->addWidget(this->settingsDisplay);
        //this->ui->horizontalLayout->addWidget();

        //enable an autosend functionality for all states
        QList<OscControlledState*> allStates =this->displayedStates->getStates();
        for (QList<OscControlledState*>::iterator i = allStates.begin(); i != allStates.end(); ++i){
            QObject::connect(*i,SIGNAL(valueChanged(OscControlledState* )),this,SLOT(updateState(OscControlledState*)));
        }

        //perform an initial update of the states
        this->displayedStates->sendAll(this->oscClient);

    }

}

void MainWindow::loadAndQuit(){
    this->displayedStates->loadFromFile(this->loadAndQuitFilename);
    this->displayedStates->sendAll(this->oscClient);
    QCoreApplication::exit();
}



void MainWindow::on_actionSave_OSC_Parameters_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,
                                                  "Save preset",this->appSettings->value("lastFile","").toString(),
                                                  "*.txt"
                                                  );
    if(filename!=""){
        this->appSettings->setValue("lastFile",filename);
        this->displayedStates->saveToFile(filename);
    }
}


void MainWindow::updateState(OscControlledState* state){
    state->sendCurrentValue(this->oscClient);
}

void MainWindow::on_actionSet_IP_triggered()
{
    bool ok;
    QString adressString=QInputDialog::getText(this, tr("Set Target IP"),
                                               tr("IP:"),
                                               QLineEdit::Normal,
                                               this->appSettings->value("targetIp","127.0.0.1").toString(),
                                               &ok);
    if(!adressString.isEmpty()){
        QHostAddress newAdress;
        if(newAdress.setAddress(adressString)){
            this->appSettings->setValue("targetIp",adressString);
            this->oscClient->setAddress(newAdress,this->appSettings->value("targetPort",8000).toInt());
        }
    }
}

void MainWindow::on_actionSet_Port_triggered()
{

    bool ok;
    int portNumber = QInputDialog::getInt(this, tr("Set Target Port"),
                                          tr("Port# :"), this->appSettings->value("targetPort",8000).toInt(), 0, 65535, 1, &ok);

    if(ok){
        QHostAddress newAdress(this->appSettings->value("targetIp","127.0.0.1").toString());
        this->appSettings->setValue("targetPort",portNumber);
        this->oscClient->setAddress(newAdress,portNumber);
    }
}



void MainWindow::on_actionNew_Blender_triggered()
{
    TwoStateBlender* newBlender=new TwoStateBlender(this->displayedStates,this->displayedStates,this);
    QDockWidget* dock=new QDockWidget("Some Blender",this);
    QWidget* newBlenderWidget=newBlender->makeUserControl(dock);
    dock->setWidget(newBlenderWidget);
    newBlender->setParent(newBlenderWidget);
    this->addDockWidget(Qt::BottomDockWidgetArea, dock);
}

void MainWindow::on_actionSendCurrent_triggered()
{
        this->displayedStates->sendAll(this->oscClient);
}
