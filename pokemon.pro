TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT       += core gui
QT       += sql

SOURCES += \
        dresseur.cpp \
        electrik.cpp \
        feu.cpp \
        game.cpp \
        main.cpp \
        mybd.cpp \
        plant.cpp \
        pokemon.cpp \
        water.cpp

HEADERS += \
    color.h \
    dresseur.h \
    electrik.h \
    feu.h \
    game.h \
    mybd.h \
    plant.h \
    pokemon.h \
    typeDef.h \
    water.h


