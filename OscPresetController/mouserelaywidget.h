#ifndef MOUSERELAYWIDGET_H
#define MOUSERELAYWIDGET_H

#include <QWidget>

class MouseRelayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MouseRelayWidget(QWidget *parent = 0);

signals:
    void mouseSignal(double x, double y, int buttons); ///< pass on information from mouse events
public slots:
protected:
    void mouseMoveEvent ( QMouseEvent * event ); ///< reimplement mouse move handling to capture moves...
    void mousePressEvent ( QMouseEvent * event );///< reimplement mouse move handling to capture moves...
    void mouseReleaseEvent ( QMouseEvent * event );///< reimplement mouse move handling to capture moves...
};

#endif // MOUSERELAYWIDGET_H
