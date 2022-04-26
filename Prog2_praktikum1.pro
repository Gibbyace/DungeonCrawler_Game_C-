TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        character.cpp \
        dungeoncrawler.cpp \
        klassabstractui.cpp \
        level.cpp \
        main.cpp \
        portal.cpp \
        terminalui.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
   character.h \
   dungeoncrawler.h \
   klassabstractui.h \
   level.h \
   portal.h \
   terminalui.h \
   tile.h \
   wall.h
