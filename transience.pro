#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T12:11:14
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = transience
TEMPLATE = app


SOURCES += main.cpp\
        debugwindow.cpp \
    dothint.cpp \
    hintmanager.cpp \
    hintmanageradapter.cpp

HEADERS  += debugwindow.h \
    dothint.h \
    hintmanager.h \
    hintmanageradapter.h

FORMS    += debugwindow.ui

OTHER_FILES +=
