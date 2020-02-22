TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    neuron.cpp \
    heavyside.cpp \
    sigmoid.cpp \
    distancecalculation.cpp \
    weightsum.cpp \
    testneuron.cpp \
    multilayerperceptron.cpp \
    dataset.cpp \
    TextParser.cpp \
    system.cpp

HEADERS += \
    neuron.h \
    input.h \
    activatefunction.h \
    aggregationfunction.h \
    heavyside.h \
    sigmoid.h \
    distancecalculation.h \
    weightsum.h \
    testneuron.h \
    multilayerperceptron.h \
    randomgenerator.h \
    data.h \
    dataset.h \
    TextParser.h \
    system.h
