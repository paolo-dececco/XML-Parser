QT   += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        xmlcontent.cpp \
        xmlelement.cpp \
        xmlparser.cpp \
        xmlvariable.cpp

HEADERS += \
    mainwindow.h \
    xmlcontent.h \
    xmlelement.h \
    xmlparser.h \
    xmlvariable.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
