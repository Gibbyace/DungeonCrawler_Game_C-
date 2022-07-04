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
        attackcontroller.cpp \
        character.cpp \
        controller.cpp \
        door.cpp \
        dungeoncrawler.cpp \
        endscreen.cpp \
        floor.cpp \
        graph.cpp \
        graphicalui.cpp \
        guardcontroller.cpp \
        level.cpp \
        levelchanger.cpp \
        levellist.cpp \
        levelloader.cpp \
        levelsaver.cpp \
        lootchest.cpp \
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
   attackcontroller.h \
   character.h \
   controller.h \
   door.h \
   dungeoncrawler.h \
   endscreen.h \
   floor.h \
   graph.h \
   graphicalui.h \
   guardcontroller.h \
   level.h \
   levelchanger.h \
   levellist.h \
   levelloader.h \
   levelsaver.h \
   lootchest.h \
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
   wall.h  \
   json.hpp

FORMS += \
   endscreen.ui \
   mainwindow.ui \
   startscreen.ui
