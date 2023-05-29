QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_unittest.cpp \
    ../pokemon/dresseur.cpp \
    ../pokemon/feu.cpp \
    ../pokemon/pokemon.cpp \
    ../pokemon/water.cpp

HEADERS += \
    ../pokemon/dresseur.h \
    ../pokemon/feu.h \
    ../pokemon/pokemon.h \
    ../pokemon/water.h
