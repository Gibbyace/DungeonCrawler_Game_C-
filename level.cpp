#include "level.h"
#include <vector>
#include <string>
#include "portal.h"
#include "floor.h"
#include "lootchest.h"
#include "wall.h"
#include "tile.h"
#include "switch.h"
#include "door.h"
#include "pit.h"
#include "ramp.h"
#include "stationarycontroller.h"
#include "guardcontroller.h"

int Level::idCounter = 0;

Level::Level(const Level& level) : height(level.height), width(level.width) {
    int charRow, charCol;

    for (int row = 0; row < height; row++) {
        vector<Tile*> newRow;

        for (int col = 0; col < width; col++) {
            newRow.push_back(nullptr);
        }

        this->tilepointer.push_back(newRow);
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (this->tilepointer[row][col] != nullptr) {
                continue;
            }

            Tile* tile = level.getTilepointer()[row][col];

            if (dynamic_cast<Door*>(tile) != nullptr) {
                tilepointer[row][col] = new Door(row, col);
            }
            else if (dynamic_cast<Floor*>(tile) != nullptr) {
                tilepointer[row][col] = new Floor(row, col);
            }
            else if (dynamic_cast<LootChest*>(tile) != nullptr) {
                tilepointer[row][col] = new LootChest(row, col);
            }
            else if (dynamic_cast<Pit*>(tile) != nullptr) {
                tilepointer[row][col] = new Pit(row, col);
            }
            else if (dynamic_cast<Portal*>(tile) != nullptr) {
                Portal* tileAsPortal = dynamic_cast<Portal*>(tile);

                int destRow = tileAsPortal->getDestination()->getRow();
                int destCol = tileAsPortal->getDestination()->getColumn();

                Portal* newPortal = new Portal(row, col);
                Tile* destPortal = new Portal(destRow, destCol);

                dynamic_cast<Portal*>(destPortal)->setDestination(newPortal);
                dynamic_cast<Portal*>(newPortal)->setDestination(destPortal);

                tilepointer[destRow][destCol] = destPortal;
                tilepointer[row][col] = newPortal;
            }
            else if (dynamic_cast<Ramp*>(tile) != nullptr) {
                tilepointer[row][col] = new Ramp(row, col);
            }
            else if (dynamic_cast<Switch*>(tile) != nullptr) {
                Switch* tileAsSwitch = dynamic_cast<Switch*>(tile);
                vector<Passive*> observers = tileAsSwitch->getObservers();

                Switch* newSwitch = new Switch(row, col);

                for (unsigned i = 0; i < observers.size(); i++) {
                    if (dynamic_cast<Door*>(observers[i]) != nullptr) {
                        int obsRow = dynamic_cast<Tile*>(observers[i])->getRow();
                        int obsCol = dynamic_cast<Tile*>(observers[i])->getColumn();

                        Door* newDoor = new Door(obsRow, obsCol);

                        tilepointer[obsRow][obsCol] = newDoor;
                        newSwitch->attach(newDoor);
                    }
                }

                tilepointer[row][col] = newSwitch;
            }
            else if (dynamic_cast<Wall*>(tile) != nullptr) {
                tilepointer[row][col] = new Wall(row, col);
            }

            if (tile->hasCharacter()) {
                charRow = row;
                charCol = col;
            }
        }
    }

    Character* new_character = new Character(10, 10, 10, true);
    placeCharacter(new_character, charRow, charCol);
    characterpointer.push_back(new_character);
}

void swap(Level& lhs, Level& rhs) {
    std::swap(lhs.tilepointer, rhs.tilepointer);
    std::swap(lhs.characterpointer, rhs.characterpointer);
}

Level& Level::operator=(Level rhs) {
    swap(*this, rhs);
    return *this;
}

bool Level::operator ==(Level* rhs) {
    return this->id == rhs->id;
}

const vector<vector<Tile *> > &Level::getTilepointer() const
{
    return tilepointer;
}

int Level::getHeight() const
{
    return height;
}

int Level::getWidth() const
{
    return width;
}

Character* Level::getPlayerCharacter() {
    vector<Character*> characters = getCharacterpointer();

    for (unsigned i = 0; i < characters.size(); i++) {
        if (characters[i]->getIsPlayerCharacter()) {
            return characters[i];
        }
    }
}

int Level::getId() const
{
    return id;
}// TODO: falls nicht gefunden, return nullptr;

const vector<Character *> &Level::getCharacterpointer() const
{
    return characterpointer;
}

Level::Level(const int height, const int width):height(height),width(width)
{
    idCounter++;
    id = idCounter;

    for (int i = 0; i < height; i++) {
        vector<Tile*> row = vector<Tile*>();
        tilepointer.push_back(row);
    }

    vector<vector<string>> level_as_string =
        {
            {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", "N", "#"},
            {"#", "_", "_", "_", ".", ".", ".", "e", ".", "#"},
            {"#", "_", "_", "<", ".", "X", ".", ".", ".", "#"},
            {"#", "_", "_", "_", ".", ".", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
            {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        };

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            string tileAsString = level_as_string[row][col];

            if (tileAsString == "#") {
                tilepointer[row].push_back(new Wall(row, col));
            }
            else if(tileAsString == "_"){
                tilepointer[row].push_back(new Pit(row, col));
            }
            else if(tileAsString == "<"){
                tilepointer[row].push_back(new Ramp(row, col));
            }
            else if(tileAsString == "e"){
                tilepointer[row].push_back(new LootChest(row, col));
            }

            else {
                Floor* new_floor = new Floor(row, col);
                tilepointer[row].push_back(new_floor);

                if (tileAsString == "X") {
                    Character* new_character = new Character(10, 10, 10, true);
                    placeCharacter(new_character, row, col);

                    characterpointer.push_back(new_character);
                }
                else if (tileAsString == "N") {
                    Character* newNpc = new Character(10, 10, 10, false);
                    Controller* npcController = new GuardController({4, 4, 2, 6, 6, 6});
                    newNpc->setController(npcController);

                    placeCharacter(newNpc, row, col);

                    characterpointer.push_back(newNpc);
                }
            }
        }
    }

    placePortals(1, 1, 8, 8);
    placePortals(1, 8, 8, 1);

    placeSwitchAndDoor(2, 2, 7, 7);

}

Level::~Level() {
    for (int row = 0; row < this->height; row++) {
        while (!tilepointer[row].empty()) {
            delete tilepointer[row].back();
            tilepointer[row].pop_back();
        }
    }

    while (!characterpointer.empty()) {
        delete characterpointer.back();
        characterpointer.pop_back();
    }
}

Tile* Level::getTile(int row, int col) {
    return tilepointer[row][col];
}

Tile* Level::getLootChest(int row, int col) {
    return tilepointer[row][col];
}

void Level::placeCharacter(Character *c, int row, int col) {
    tilepointer[row][col]->setCharacter(c);
    c->setTile(tilepointer[row][col]);
}

void Level::placePortals(int row1, int col1, int row2, int col2) {
    Tile* newPortal1 = new Portal(row1, col1);
    Tile* newPortal2 = new Portal(row2, col2);

    dynamic_cast<Portal*>(newPortal1)->setDestination(newPortal2);
    dynamic_cast<Portal*>(newPortal2)->setDestination(newPortal1);

    delete tilepointer[row1][col1];
    delete tilepointer[row2][col2];

    tilepointer[row1][col1] = newPortal1;
    tilepointer[row2][col2] = newPortal2;
}

void Level::placeSwitchAndDoor(int row1, int col1, int row2, int col2) { //TODO: Aufteilen, damit mehrere switches, gleiche tür
    Tile* newSwitch = new Switch(row1, col1);
    Tile* newDoor = new Door(row2, col2);

    dynamic_cast<Switch*>(newSwitch)->attach(dynamic_cast<Passive*>(newDoor));

    tilepointer[row1][col1] = newSwitch;
    tilepointer[row2][col2] = newDoor;
}
