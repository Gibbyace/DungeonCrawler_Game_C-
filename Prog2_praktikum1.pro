TEMPLATE = app
QT += core gui
QT += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt

SOURCES += \
        abstractui.cpp \
        active.cpp \
        character.cpp \
        controller.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        floor.cpp \
        graphicalui.cpp \
        guardcontroller.cpp \
        level.cpp \
        main.cpp \
        mainwindow.cpp \
        passive.cpp \
        pit.cpp \
        portal.cpp \
        ramp.cpp \
        startscreen.cpp \
        stationarycontroller.cpp \
        switch.cpp \
        terminalui.cpp \
        texturecontainer.cpp \
        tile.cpp \
        wall.cpp

HEADERS += \
   abstractui.h \
   active.h \
   character.h \
   controller.h \
   door.h \
   dungeoncrawler.h \
   floor.h \
   graphicalui.h \
   guardcontroller.h \
   level.h \
   mainwindow.h \
   passive.h \
   pit.h \
   portal.h \
   ramp.h \
   startscreen.h \
   stationarycontroller.h \
   switch.h \
   terminalui.h \
   texturecontainer.h \
   tile.h \
   wall.h

FORMS += \
   mainwindow.ui \
   startscreen.ui
