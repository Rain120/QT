#-------------------------------------------------
#
# Project created by QtCreator 2016-08-26T15:50:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tcpServer-3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tcpclientsocket.cpp \
    tcpserver.cpp \
    server.cpp \
    common.cpp

HEADERS  += mainwindow.h \
    tcpclientsocket.h \
    tcpserver.h \
    server.h \
    common.h

FORMS    += mainwindow.ui
