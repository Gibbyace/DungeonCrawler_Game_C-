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
        string direction = terminalUI->askUserForDirection();
        Tile* tileWithCharacter = character->getTile();
        Tile* destinationTile = determineDestinationTile(level, tileWithCharacter, direction); //falls es nicht geht, wird destinationTile nullptr

        if (destinationTile != nullptr) {
            tileWithCharacter->moveTo(destinationTile, character);
        }

    }
    while(true);

}

Tile* DungeonCrawler::determineDestinationTile(Level* level, Tile *tileWithCharacter, string direction) {
    int rowWithCharacter = tileWithCharacter->getRow();
    int colWithCharacter = tileWithCharacter->getColumn();
    int rowDestination = rowWithCharacter;
    int colDestination = colWithCharacter;
    bool movementImpossible = false;

    if (direction == "up") {
        if (rowWithCharacter - 1 >= 0) {
            rowDestination = rowWithCharacter - 1;
        }
        else {
            movementImpossible = true;
        }
    }
    else if (direction == "down") {
        if (rowWithCharacter + 1 < level->getHeight()) {
            rowDestination = rowWithCharacter + 1;
        }
        else {
            movementImpossible = true;
        }
    }
    else if (direction == "left") {
        if (colWithCharacter - 1 >= 0) {
            colDestination = colWithCharacter - 1;
        }
        else {
            movementImpossible = true;
        }
    }
    else if (direction == "right") {
        if (colWithCharacter + 1 < level->getWidth()) {
            colDestination = colWithCharacter + 1;
        }
        else {
            movementImpossible = true;
        }
    }

    if (movementImpossible) {
        return nullptr;
    }

    Tile* destinationTile = level->getTilepointer()[rowDestination][colDestination];

    return destinationTile;
}
