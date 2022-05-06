TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        abstractui.cpp \
        character.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        level.cpp \
        main.cpp \
        portal.cpp \
        terminalui.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
   abstractui.h \
   character.h \
   dungeoncrawler.h \
   floor.h \
   level.h \
   portal.h \
   terminalui.h \
   tile.h \
   wall.h
