#include "dungeoncrawler.h"
#include "character.h"
#include "terminalui.h"
#include "level.h"

DungeonCrawler::DungeonCrawler()
{

}

void DungeonCrawler::play(){
    //Initialisierung
    TerminalUI* terminalUI = new TerminalUI();
    Level* level = new Level(6, 6);
    this->levels.push_back(level);

    //Schleife, die für jeden Spielzug einmal durchläuft;
    do{
        terminalUI->draw(level);

        Character* character = level->getCharacterpointer()[0];
        //string direction = terminalUI->askUserForDirection();
        int direction = character->move();

        if (direction == 0) {
            return;
        }

        Tile* tileWithCharacter = character->getTile();
        Tile* destinationTile = determineDestinationTile(level, tileWithCharacter, direction); //falls es nicht geht, wird destinationTile nullptr

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
