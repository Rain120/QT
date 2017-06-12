#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T14:26:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpClient-3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclientsocket.cpp

HEADERS  += mainwindow.h \
    tcpclientsocket.h

FORMS    += mainwindow.ui
