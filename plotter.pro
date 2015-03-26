# -------------------------------------------------
# Project created by QtCreator 2010-12-24T16:46:08
# -------------------------------------------------
QT += svg
TARGET = plotter
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    plotter.cpp \
    item.cpp \
    workspace.cpp \
    ftable.cpp \
    comm.cpp \
    cmdengine.cpp
HEADERS += mainwindow.h \
    plotter.h \
    workspace.h \
    matrix.h \
    item.h \
    ftable.h \
    comm.h \
    cmdengine.h
FORMS += mainwindow.ui \
    plotter.ui
QWT_ROOT = ../..
include( $${QWT_ROOT}/qwtconfig.pri )
SUFFIX_STR = 
VVERSION = $$[QT_VERSION]
isEmpty(VVERSION) { 
    # Qt 3
    debug:SUFFIX_STR = $${DEBUG_SUFFIX}
    else:SUFFIX_STR = $${RELEASE_SUFFIX}
}
else { 
    CONFIG(debug, debug|release):SUFFIX_STR = $${DEBUG_SUFFIX}
    else:SUFFIX_STR = $${RELEASE_SUFFIX}
}
TEMPLATE = app
MOC_DIR = moc
OBJECTS_DIR = obj$${SUFFIX_STR}
DESTDIR = $${QWT_ROOT}/examples/bin$${SUFFIX_STR}
QWTLIB = qwt$${SUFFIX_STR}
isEmpty(VVERSION) { 
    # Qt 3
    DEPENDPATH += /usr/include/qwt-qt3
    INCLUDEPATH += /usr/include/qwt-qt3
    LIBS += -L$${QWT_ROOT}/lib \
        -l$${QWTLIB}-qt3
}
else { 
    # Qt 4
    DEPENDPATH += /usr/include/qwt-qt4
    INCLUDEPATH += /usr/include/qwt-qt4
    LIBS += -L$${QWT_ROOT}/lib \
        -l$${QWTLIB}-qt4
}
