#include "twostateblenderwidget.h"
#include "ui_twostateblenderwidget.h"
#include <QFileDialog>

TwoStateBlenderWidget::TwoStateBlenderWidget(QString oneName, QString twoName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TwoStateBlenderWidget),
    settings(new QSettings("Homebrew","OscController",this))
{
    ui->setupUi(this);
    this->ui->state1Label->setText(oneName);
    this->ui->state2Label->setText(twoName);
}

TwoStateBlenderWidget::~TwoStateBlenderWidget()
{
    delete ui;
}

void TwoStateBlenderWidget::setOneName(QString name){
    this->ui->state1Label->setText(name);
}

void TwoStateBlenderWidget::setTwoName(QString name){
    this->ui->state2Label->setText(name);
}

void TwoStateBlenderWidget::setFraction(double fractionOfOne){
    this->ui->horizontalSlider->setValue(fractionOfOne*128.0);
}

void TwoStateBlenderWidget::on_load1PushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
                                                  "Choose preset",this->settings->value("lastFile","").toString(),
                                                  "*.txt"
                                                  );
    if(filename!=""){
        emit this->loadFileToOne(filename);
    }
}

void TwoStateBlenderWidget::on_load2pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
                                                  "Choose preset",this->settings->value("lastFile","").toString(),
                                                  "*.txt"
                                                  );
    if(filename!=""){
        emit this->loadFileToTwo(filename);
    }
}

void TwoStateBlenderWidget::on_setCurrentAs1PushButton_clicked()
{
    emit this->loadCurrentToOne();
}

void TwoStateBlenderWidget::on_setCurrentAs2PushButton_clicked()
{
    emit this->loadCurrentToTwo();
}

void TwoStateBlenderWidget::on_horizontalSlider_valueChanged(int value)
{
    emit this->fractionChanged(1.0-((double)value)/128.0);
}
