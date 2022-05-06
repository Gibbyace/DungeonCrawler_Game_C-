#include "dungeoncrawler.h"
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

    //das geht bestimmt noch schöner

    //up
    if (direction == 8) {
        if (rowWithCharacter - 1 >= 0) {
            rowDestination -= 1;
        }
        else {
            return nullptr;
        }
    }
    //up right
    else if (direction == 9) {
        if (rowWithCharacter - 1 >= 0 && colWithCharacter + 1 < level->getWidth()) {
            rowDestination -= 1;
            colDestination += 1;
        }
        else {
            return nullptr;
        }
    }
    //right
    else if (direction == 6) {
        if (colWithCharacter + 1 < level->getWidth()) {
            colDestination = colWithCharacter + 1;
        }
        else {
            return nullptr;
        }
    }
    //down right
    else if (direction == 3) {
        if (colWithCharacter + 1 < level->getWidth() && rowWithCharacter + 1 < level->getHeight()) {
            rowDestination += 1;
            colDestination += 1;
        }
        else {
            return nullptr;
        }
    }
    //down
    else if (direction == 2) {
        if (rowWithCharacter + 1 < level->getHeight()) {
            rowDestination += 1;
        }
        else {
            return nullptr;
        }
    }
    //down left
    else if (direction == 1) {
        if (rowWithCharacter + 1 < level->getHeight() && colWithCharacter - 1 >= 0) {
            rowDestination += 1;
            colDestination -= 1;
        }
        else {
            return nullptr;
        }
    }
    //left
    else if (direction == 4) {
        if (colWithCharacter - 1 >= 0) {
            colDestination -= 1;
        }
        else {
            return nullptr;
        }
    }
    //up left
    else if (direction == 7) {
        if (colWithCharacter - 1 >= 0 && rowWithCharacter -1 >= 0) {
            rowDestination -= 1;
            colDestination -= 1;
        }
        else {
            return nullptr;
        }
    }

    Tile* destinationTile = level->getTilepointer()[rowDestination][colDestination];

    return destinationTile;
}
