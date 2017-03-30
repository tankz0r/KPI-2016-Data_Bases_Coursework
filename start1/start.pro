#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T13:43:24
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = start
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    mainform.cpp \
    documentbuy.cpp \
    counteragent.cpp \
    mainwindow.cpp

HEADERS  += login.h \
    mainform.h \
    documentbuy.h \
    counteragent.h \
    mainwindow.h

FORMS    += login.ui \
    mainform.ui \
    documentbuy.ui \
    counteragent.ui \
    mainwindow.ui

RESOURCES += \
    resources.qrc
