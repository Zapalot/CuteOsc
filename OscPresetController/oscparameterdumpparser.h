#ifndef OSCPARAMETERDUMPPARSER_H
#define OSCPARAMETERDUMPPARSER_H

#include <QObject>
#include <QList>
#include <QString>
#include <QFile>
#include <QStringList>

#include <osccontrolledstate.h>
#include "osccontrolledfloat.h"
#include "osccontrolledint.h"
#include "osccontrolledstring.h"
#include "osccontrolledtrigger.h"
#include "osccontrolledfloatvector.h"
#include "osccontrolledmouserelay.h"

class OscParameterDumpParser : public QObject
{
    Q_OBJECT
public:
    explicit OscParameterDumpParser(QObject *parent = 0);
    static QList<OscControlledState*> parseFile(QString filename, QObject *parent = 0);
signals:

public slots:

};

#endif // OSCPARAMETERDUMPPARSER_H
