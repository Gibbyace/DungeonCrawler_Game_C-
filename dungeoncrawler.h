#ifndef DUNGEONCRAWLER_H
#define DUNGEONCRAWLER_H
#include "abstractui.h"
#include "level.h"
#include "passive.h"
#include "levellist.h"

class DungeonCrawler : public Passive
{
private:
    AbstractUI* abstractUI;
    LevelList levels;
    Level* currentLevel;
    //vector<Level*> levels;


public:
    DungeonCrawler();
    ~DungeonCrawler();

    void play();
    void setLevel(Level* level);
    Tile* determineDestinationTile(Level* level, Tile* tileWithCharacter, int direction);
    void notify(Active* source) override;
};

#endif // DUNGEONCRAWLER_H
