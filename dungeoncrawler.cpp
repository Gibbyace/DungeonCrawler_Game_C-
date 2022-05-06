#include "dungeoncrawler.h"
#include "character.h"
#include "terminalui.h"
#include "level.h"

DungeonCrawler::DungeonCrawler()
{

}

void DungeonCrawler::play(){
    //Initialisierung
    Level* level = new Level(6, 6);
    this->levels.push_back(level);

    //Schleife, die für jeden Spielzug einmal durchläuft;
    do{




    }
    while(true);

}
