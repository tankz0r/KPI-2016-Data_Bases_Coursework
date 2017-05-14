unix {
    macx: QMAKE_LFLAGS += -F$$NCREPORT_LIBPATH
    else: target.path = /usr/local/NCReport/bin
}

CONFIG(release, debug|release) {
    win32|win64:  LIBS += -L$$NCREPORT_LIBPATH -lNCReport2
    unix:!macx:   LIBS += -L$$NCREPORT_LIBPATH -lNCReport
    else:macx:    LIBS += -framework NCReport
}
CONFIG(debug, debug|release) {
    win32|win64:  LIBS += -L$$NCREPORT_LIBPATH -lNCReportDebug2
    unix:!macx:   LIBS += -L$$NCREPORT_LIBPATH -lNCReportDebug
    else:macx:    LIBS += -framework NCReportDebug
}
