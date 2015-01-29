TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CC= gcc -std=c99
LIBS += -Lm

SOURCES += main.c \
    color.c \
    image.c \
    effect.c \
    utils.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    color.h \
    image.h \
    effect.h \
    utils.h

