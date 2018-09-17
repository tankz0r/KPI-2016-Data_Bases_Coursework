QT = xml sql gui core
greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport widgets
CONFIG += warn_on qt thread
TEMPLATE = app
MOC_DIR = moc
OBJECTS_DIR = obj
UI_DIR = uic
macx: ICON = ../../images/icon/ncreport.icns

TARGET = NCReportRunner
INSTALLS = target
RC_FILE = runner.rc
DESTDIR = ../../bin
DEFINES += QT_NO_DEBUG_OUTPUT

HEADERS += ncrtestform.h \
	testitemrendering.h \
	testdatasource.h
SOURCES += main.cpp \
	ncrtestform.cpp \
	testitemrendering.cpp \
	testdatasource.cpp

FORMS += ncrtestform.ui

INCLUDEPATH += $$PWD/../ncreport
NCREPORT_LIBPATH = $$OUT_PWD/../../lib
include(../ncreport_library.pri)
include(../target.pri)




