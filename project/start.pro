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

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

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
    enhancedtablewidget.cpp \
    qcustomplot/qcustomplot.cpp \
    graph.cpp

HEADERS  += login.h \
    mainform.h \
    counteragent.h \
    documbuy.h \
    movedoc.h \
    qungoods.h \
    test.h \
    errorwindow.h \
    enhancedtablewidget.h \
    qcustomplot/qcustomplot.h \
    graph.h

FORMS    += login.ui \
    mainform.ui \
    counteragent.ui \
    documbuy.ui \
    movedoc.ui \
    qungoods.ui \
    errorwindow.ui \
    graph.ui

RESOURCES += \
    resources.qrc


#unix:!macx: LIBS += -L$$PWD/NCReport2.20.3.x64.Qt4.8.6.eval/lib/ -lNCReport

#INCLUDEPATH += $$PWD/NCReport2.20.3.x64.Qt4.8.6.eval/include
#DEPENDPATH += $$PWD/NCReport2.20.3.x64.Qt4.8.6.eval/include



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/NCReport2.20.3.x64.Qt5.8.0.eval/lib/release/ -lNCReport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/NCReport2.20.3.x64.Qt5.8.0.eval/lib/debug/ -lNCReport
else:unix: LIBS += -L$$PWD/NCReport2.20.3.x64.Qt5.8.0.eval/lib/ -lNCReport

INCLUDEPATH += $$PWD/NCReport2.20.3.x64.Qt5.8.0.eval/include
DEPENDPATH += $$PWD/NCReport2.20.3.x64.Qt5.8.0.eval/include
