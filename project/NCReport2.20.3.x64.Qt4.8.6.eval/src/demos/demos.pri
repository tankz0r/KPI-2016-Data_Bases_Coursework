greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport widgets
MOC_DIR = moc
OBJECTS_DIR = obj
UI_DIR = uic
RC_FILE = $$PWD/test.rc
macx: ICON = $$PWD/../../images/icon/ncreport.icns
INCLUDEPATH += $$PWD/../ncreport $$PWD/../runner $$PWD/../../include $$PWD/../preview
DESTDIR = $$OUT_PWD/../../../bin

#include(../target.pri)
