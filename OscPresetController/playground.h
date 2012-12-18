#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <QWidget>

namespace Ui {
    class Playground;
}

class Playground : public QWidget
{
    Q_OBJECT

public:
    explicit Playground(QWidget *parent = 0);
    ~Playground();

private:
    Ui::Playground *ui;
};

#endif // PLAYGROUND_H
