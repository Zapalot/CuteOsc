#ifndef TWOSTATEBLENDERWIDGET_H
#define TWOSTATEBLENDERWIDGET_H

#include <QWidget>
#include <QSettings>
class TwoStateBlender;
namespace Ui {
    class TwoStateBlenderWidget;
}

class TwoStateBlenderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TwoStateBlenderWidget(QString oneName, QString twoName, QWidget *parent = 0);
    ~TwoStateBlenderWidget();
public slots:
    void setOneName(QString name);
    void setTwoName(QString name);
    void setFraction(double fractionOfOne);
signals:
    void loadFileToOne(QString filename);
    void loadFileToTwo(QString filename);
    void loadCurrentToOne();
    void loadCurrentToTwo();
    void fractionChanged(double fractionOfOne);
private:

    //TwoStateBlender* baseBlender;           ///< can be used to delete the blender when the widget is deleted
    Ui::TwoStateBlenderWidget *ui;
    QSettings* settings;

private slots:
    void on_horizontalSlider_valueChanged(int value);
    void on_setCurrentAs2PushButton_clicked();
    void on_setCurrentAs1PushButton_clicked();
    void on_load2pushButton_clicked();
    void on_load1PushButton_clicked();
};

#endif // TWOSTATEBLENDERWIDGET_H
