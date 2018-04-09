TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG += c++14

SOURCES += main.cpp \
    src/Nodes/node.cpp \
    src/Nodes/activation.cpp \
    src/Nodes/activatorsfactory.cpp

HEADERS += \
    src/Nodes/node.h \
    constants.h \
    src/Nodes/activation.h \
    src/Nodes/activatorsfactory.h
