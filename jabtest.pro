TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
SOURCES += main.cpp
QMAKE_CXXFLAGS += -std=c++0x -pthread
QMAKE_CXXFLAGS += -lncurses
LIBS += -pthread -lncurses


LIBS += -L/usr/lib32 -lncurses


