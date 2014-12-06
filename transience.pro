#-------------------------------------------------
#
# Project created by QtCreator 2014-11-30T12:11:14
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = transience
TEMPLATE = app

LIBS += -framework Cocoa

SOURCES += main.cpp\
        debugwindow.cpp \
    dothint.cpp \
    screensurface.cpp \
    screensurfaceadapter.cpp

HEADERS  += debugwindow.h \
    dothint.h \
    screensurface.h \
    screensurfaceadapter.h

FORMS    += debugwindow.ui

OTHER_FILES +=

OBJECTIVE_SOURCES += \
    osxhacks.mm
