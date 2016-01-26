#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T16:16:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenTheDoor
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    etalon.cpp \
    morzewindow.cpp \
    morzecode.cpp \
    mousefilter.cpp

HEADERS  += mainwindow.h \
    etalon.h \
    morzewindow.h \
    morzecode.h \
    congra.h \
    mousefilter.h \
    blink.h \
    opendoortimer.h
FORMS    += mainwindow.ui \
    morzewindow.ui
windows:TARGET = ../OpenTheDoor

#RESOURCES += \
#    resource.qrc
