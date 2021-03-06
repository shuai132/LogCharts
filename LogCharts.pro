QT       += core gui
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogCharts
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    main.cpp \
    mvp/mainwindow/mainwindow.cpp \
    mvp/mainwindow/mainpresenter.cpp \
    mvp/mainwindow/mainmodel.cpp \
    data/sharedpreferences/sharedpreferences.cpp \
    conf/config.cpp \
    conf/lang.cpp \
    mvp/mainwindow/charts/autochart.cpp \
    cmdfifo/cmdfifo.cpp

HEADERS += \
    conf/lang.h \
    mvp/base/mvp.h \
    mvp/mainwindow/mainwindow.h \
    mvp/mainwindow/mainpresenter.h \
    mvp/mainwindow/maincontract.h \
    mvp/mainwindow/mainmodel.h \
    data/sharedpreferences/sharedpreferences.h \
    conf/config.h \
    mvp/mainwindow/charts/autochart.h \
    cmdfifo/cmdfifo.h

FORMS += \
    mvp/mainwindow/mainwindow.ui

RESOURCES += \
    resource/state/state.qrc
