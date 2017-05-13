#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T13:43:24
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
QT       += widgets

QT += printsupport

CONFIG += c++11


#LIBS += /home/denys/NCReport2.20.3.x64.Qt4.8.6.eval/lib/libNCReport.so.2.20.3
#/libNCReport.so.2.20.1
#INCLUDEPATH += /home/denys/NCReport2.20.3.x64.Qt4.8.6.eval/include
#INCLUDEPATH += /home/denys/Downloads/NCReport2.20.3.x64.Qt4.8.6.eval/include

#unix {
#LIBS += -L /home/denys/Downloads/NCReport2.20.3.x64.Qt4.8.6.eval/lib
       #  target.path = /usr/lib
#LIBS += /usr/lib/libNCReport.so.2.20.3
#}

#ls -s /home/denys/Downloads/NCReport2.20.3.x64.Qt4.8.6.eval/lib/libNCReport.so.2.20.3 /usr/lib



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = start
TEMPLATE = app

SOURCES += main.cpp\
        login.cpp \
    mainform.cpp \
    counteragent.cpp \
    documbuy.cpp \
    movedoc.cpp \
    qungoods.cpp \
    errorwindow.cpp\
    enhancedtablewidget.cpp

HEADERS  += login.h \
    mainform.h \
    counteragent.h \
    documbuy.h \
    movedoc.h \
    qungoods.h \
    test.h \
    errorwindow.h \
    enhancedtablewidget.h

FORMS    += login.ui \
    mainform.ui \
    counteragent.ui \
    documbuy.ui \
    movedoc.ui \
    qungoods.ui \
    errorwindow.ui

RESOURCES += \
    resources.qrc
