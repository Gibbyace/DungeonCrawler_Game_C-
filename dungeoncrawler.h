#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "klassabstractui.h"
#include "level.h"


class DungeonCrawler
{
    KlassAbstractUI* AbstractUI;
    Level* level[];



public:
    DungeonCrawler();
    //Für character move aufrufen
    //dann wie in 1.4 ablauf
    void play();

};

#endif // DUNGEONCRAWLER_H
