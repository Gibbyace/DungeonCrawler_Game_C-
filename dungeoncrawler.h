#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "level.h"


class DungeonCrawler
{
    AbstractUI* AbstractUI;
    vector<Level*> levels;



public:
    DungeonCrawler();
    //Für character move aufrufen
    //dann wie in 1.4 ablauf
    void play();
    Tile* determineDestinationTile(Level* level, Tile* tileWithCharacter, int direction);
};

#endif // DUNGEONCRAWLER_H
