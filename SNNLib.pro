TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
#CONFIG += c++14

INCLUDEPATH += $${PWD}/src
SRCPATH += $${PWD}/src

SOURCES += main.cpp \
    src/Nodes/node.cpp \
    src/Nodes/activation.cpp \
    src/Nodes/activatorsfactory.cpp \
    src/Nodes/stubactivation.cpp \
    src/Layers/layer.cpp \
    src/Layers/dense.cpp \
    src/Nodes/simplenode.cpp \
    src/Models/abstractmodel.cpp \
    src/Models/model.cpp

HEADERS += \
    src/Nodes/node.h \
    constants.h \
    src/Nodes/activation.h \
    src/Nodes/activatorsfactory.h \
    src/Nodes/stubactivation.h \
    src/Layers/layer.h \
    src/Layers/dense.h \
    src/Nodes/simplenode.h \
    src/Models/abstractmodel.h \
    src/Models/model.h
