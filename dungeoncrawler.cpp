﻿#include "dungeoncrawler.h"
#include "character.h"
#include "terminalui.h"
#include "level.h"

DungeonCrawler::DungeonCrawler()
{
    this->AbstractUI = new TerminalUI();
    Level* level = new Level(6, 6);
    this->levels.push_back(level);

}

void DungeonCrawler::play(){
    do{
        Level* currentLevel = levels[0];
        Character* character = currentLevel->getCharacterpointer()[0];

        AbstractUI->draw(currentLevel);

        int direction = character->move();

        if (direction == 0) {
            return;
        }

        Tile* tileWithCharacter = character->getTile();
        Tile* destinationTile = determineDestinationTile(currentLevel, tileWithCharacter, direction);

        if (destinationTile != nullptr) {
            tileWithCharacter->moveTo(destinationTile, character);
        }
    }
    while(true);
}

Tile* DungeonCrawler::determineDestinationTile(Level* level, Tile *tileWithCharacter, int direction) {
    int rowWithCharacter = tileWithCharacter->getRow();
    int colWithCharacter = tileWithCharacter->getColumn();
    int rowDestination = rowWithCharacter;
    int colDestination = colWithCharacter;

    if (direction == 9 || direction == 7 || direction == 8) {
        if (rowWithCharacter -1 >= 0) {
            rowDestination -= 1;
        }
        else {
            return nullptr;
        }
    }

    else if (direction == 1 || direction == 2 || direction == 3) {
        if (rowWithCharacter + 1 < level->getHeight()) {
            rowDestination += 1;
        }
        else {
            return nullptr;
        }
    }

    if (direction == 7 || direction == 4 || direction == 1) {
        if (colWithCharacter - 1 >= 0) {
            colDestination -= 1;
        }
        else {
            return nullptr;
        }
    }

    else if (direction == 9 || direction == 6 || direction == 3) {
        if (colWithCharacter + 1 < level->getWidth()) {
            colDestination += 1;
        }
        else {
            return nullptr;
        }
    }

    Tile* destinationTile = level->getTilepointer()[rowDestination][colDestination];

    return destinationTile;
}
