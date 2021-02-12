#-------------------------------------------------
#
# Project created by QtCreator 2011-03-16T10:24:59
#
#-------------------------------------------------

QT       += core gui widgets
QT += network
TARGET = OscPresetController
TEMPLATE = app

INCLUDEPATH += ../libofqf

SOURCES += main.cpp\
        mainwindow.cpp \
    ../libofqf/qosctypes.cpp \
    ../libofqf/qoscserver.cpp \
    ../libofqf/qoscclient.cpp \
    osccontrolledstate.cpp \
    osccontrolledfloat.cpp \
    oscparameterdumpparser.cpp \
    osctreenode.cpp \
    oscstateset.cpp \
    osccontrolledtrigger.cpp \
    osccontrolledint.cpp \
    osccontrolledbool.cpp \
    osccontrolledfloatvector.cpp \
    multislidersettingwidget.cpp \
    abstracttransition.cpp \
    twostateblender.cpp \
    twostateblenderwidget.cpp \
    vectorpadwidget.cpp \
    osccontrolledmouserelay.cpp \
    mouserelaywidget.cpp \
    osccontrolledquad2f.cpp \
    osccontrolledenum.cpp \
    playground.cpp \
    osccontrolledstring.cpp \
    stringsettingwidget.cpp

HEADERS  += mainwindow.h \
    ../libofqf/qosctypes.h \
    ../libofqf/qoscserver.h \
    ../libofqf/qoscclient.h \
    osccontrolledstate.h \
    osccontrolledfloat.h \
    oscparameterdumpparser.h \
    osctreenode.h \
    oscstateset.h \
    osccontrolledtrigger.h \
    osccontrolledint.h \
    osccontrolledbool.h \
    osccontrolledfloatvector.h \
    multislidersettingwidget.h \
    abstracttransition.h \
    twostateblender.h \
    twostateblenderwidget.h \
    vectorpadwidget.h \
    osccontrolledmouserelay.h \
    mouserelaywidget.h \
    osccontrolledquad2f.h \
    osccontrolledenum.h \
    playground.h \
    osccontrolledstring.h \
    stringsettingwidget.h

FORMS    += mainwindow.ui \
    twostateblenderwidget.ui \
    playground.ui
