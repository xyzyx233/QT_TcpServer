#-------------------------------------------------
#
# Project created by QtCreator 2016-07-04T16:08:01
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        serverdialog.cpp \
    fileop.cpp \
    queuemanagment.cpp \
    tcpclientsocket.cpp \
    tcp.cpp

HEADERS  += serverdialog.h \
    fileop.h \
    queuemanagment.h \
    tcpclientsocket.h \
    tcp.h

FORMS    += serverdialog.ui
