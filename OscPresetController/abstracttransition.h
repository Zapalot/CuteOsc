#ifndef ABSTRACTTRANSITION_H
#define ABSTRACTTRANSITION_H

#include <QObject>
#include <QWidget>

class AbstractTransition : public QObject
{
    Q_OBJECT
public:
    explicit AbstractTransition(QObject *parent = 0);
    virtual QWidget* makeUserControl(QWidget* parent)=0;
signals:

public slots:

};

#endif // ABSTRACTTRANSITION_H
