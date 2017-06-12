#-------------------------------------------------
#
# Project created by QtCreator 2017-06-05T10:58:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = desktopClock
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clock.cpp \
    digitalclock.cpp \
    calendar.cpp

HEADERS  += mainwindow.h \
    clock.h \
    digitalclock.h \
    calendar.h

FORMS    += mainwindow.ui
