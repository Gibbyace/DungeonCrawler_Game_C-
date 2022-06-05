#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "level.h"

class DungeonCrawler
{
private:
    AbstractUI* abstractUI;
    vector<Level*> levels;

public:
    DungeonCrawler();
    ~DungeonCrawler();
    void play();
    Tile* determineDestinationTile(Level* level, Tile* tileWithCharacter, int direction);
};

#endif // DUNGEONCRAWLER_H
