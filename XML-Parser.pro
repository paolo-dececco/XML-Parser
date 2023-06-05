TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        xmlcontent.cpp \
        xmlelement.cpp \
        xmlparser.cpp \
        xmlvariable.cpp

HEADERS += \
    xmlcontent.h \
    xmlelement.h \
    xmlparser.h \
    xmlvariable.h
