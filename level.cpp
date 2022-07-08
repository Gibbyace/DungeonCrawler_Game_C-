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
#include "levelchanger.h"
#include "attackcontroller.h"
#include "stationarycontroller.h"
#include "guardcontroller.h"

int Level::idCounter = 0;

Level::Level(const Level& level) : height(level.height), width(level.width) {
    struct characterDataset {
        int row;
        int col;
        int isPlayer;
        int strength;
        int stamina;
        int hitpoints;
    };

    vector<characterDataset> characterData;

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
            else if (dynamic_cast<Levelchanger*>(tile) != nullptr) {
                Levelchanger* tileAsLevelchanger = dynamic_cast<Levelchanger*>(tile);
                Levelchanger* newLevelchanger = new Levelchanger(row, col);

                newLevelchanger->setDestinationLevel(tileAsLevelchanger->getDestinationLevel());
                levelchangers.push_back(newLevelchanger);

                tilepointer[row][col] = newLevelchanger;
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
                Character* oldCharacter = tile->getCharacter();

                characterDataset newCharacterDataset = characterDataset();
                newCharacterDataset.row = row;
                newCharacterDataset.col = col;
                newCharacterDataset.isPlayer = oldCharacter->getIsPlayerCharacter();
                newCharacterDataset.stamina = oldCharacter->getStamina();
                newCharacterDataset.strength = oldCharacter->getStrength();
                newCharacterDataset.hitpoints = oldCharacter->getHitpoints();

                characterData.push_back(newCharacterDataset);
            }
        }
    }

    for (unsigned i = 0; i < characterData.size(); i++) {
        characterDataset set = characterData[i];
        Character* newCharacter = new Character(set.strength, set.stamina, set.hitpoints, set.isPlayer);

        if (!set.isPlayer) {
            //TODO: Controller richtig kopieren, bei GuardController auch Pattern anpassen
            Controller* npcController = new Attackcontroller(this, newCharacter);
            newCharacter->setController(npcController);
        }

        placeCharacter(newCharacter, set.row, set.col);
        characterpointer.push_back(newCharacter);
    }
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

vector<Levelchanger*> Level::getLevelchangers() const
{
    return levelchangers;
}

void Level::setId(int value)
{
    id = value;
}

void Level::setCharacterpointer(const vector<Character *> &newCharacterpointer)
{
    characterpointer = newCharacterpointer;
}

void Level::setLevelchangers(const vector<Levelchanger *> &newLevelchangers)
{
    levelchangers = newLevelchangers;
}

void Level::setTilepointer(const vector<vector<Tile *> > &newTilepointer)
{
    tilepointer = newTilepointer;
}

LevelList* Level::generateLevels() {
    LevelList* levels = new LevelList;

    Level* level1 = new Level({
        {"#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", "X", ".", ".", "#", ".", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", ".", "#", "#"},
        {"#", ".", "_", "_", ".", ".", ".", ".", "#"},
        {"#", ".", "_", "_", ".", ".", ".", ".", "#"},
        {"#", "N", "_", "<", ".", "l", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#"},
        });

    level1->placePortals(1, 1, 7, 7);
    level1->placeSwitchAndDoor(1, 4, 4, 6);

    //Kopierkonstruktor und Zuweisungsoperator testen:
    //Dafür level1 in den vorherigen Zeilen durch level0 ersetzen
    //und folgende Zeilen einkommentieren:
    /*Level* level1 = new Level(*level0);
    Level* tmp = new Level(*level0);
    *level1 = *tmp;
    delete tmp;*/

    Level* level2 = new Level({
      {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
      {"#", "X", ".", ".", ".", ".", ".", ".", ".", "#"},
      {"#", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
      {"#", ".", ".", ".", ".", ".", ".", "#", ".", "#"},
      {"#", ".", ".", ".", "#", "#", ".", "#", "N", "#"},
      {"#", ".", ".", ".", "#", ".", ".", "#", ".", "#"},
      {"#", ".", ".", ".", "#", "l", "e", "#", ".", "#"},
      {"#", "#", "#", "#", "#", "#", "#", "#", ".", "#"},
      {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
      {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
      });

    level2->placePortals(8, 1, 6, 1);
    level2->placeSwitchAndDoor(1, 3, 1, 7);
    level2->placeSwitchAndDoor(3, 8, 4, 6);

    levels->push_back(level1);
    levels->push_back(level2);

    level1->levelchangers[0]->setDestinationLevel(level2);
    level2->levelchangers[0]->setDestinationLevel(level1);

    return levels;
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

Character* Level::getNPCCharacter() {
    vector<Character*> characters = getCharacterpointer();
     for (unsigned i = 0; i < characters.size(); i++) {
         if (characters[i]->getIsPlayerCharacter() == false) {
             return characters[i];
         }
     }

     return nullptr;
}

Character* Level::getPlayerCharacter() {
    vector<Character*> characters = getCharacterpointer();

    for (unsigned i = 0; i < characters.size(); i++) {
        if (characters[i]->getIsPlayerCharacter()) {
            return characters[i];
        }
    }

    return nullptr;
}

int Level::getId() const
{
    return id;
}

const vector<Character *> &Level::getCharacterpointer() const
{
    return characterpointer;
}

void Level::characterpointerpushback(Character *character)
{
    characterpointer.push_back(character);
}

Level::Level(vector<vector<string>> level_as_string) {
    //idCounter++;
    //id = idCounter;

    height = level_as_string.size();
    width = level_as_string[0].size();

    for (int i = 0; i < height; i++) {
        vector<Tile*> row = vector<Tile*>();
        tilepointer.push_back(row);
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            string tileAsString = level_as_string[row][col];

            if (tileAsString == "#") {
                tilepointer[row].push_back(new Wall(row, col));
            }
            else if (tileAsString == "_") {
                tilepointer[row].push_back(new Pit(row, col));
            }
            else if (tileAsString == "<") {
                tilepointer[row].push_back(new Ramp(row, col));
            }
            else if (tileAsString == "e") {
                tilepointer[row].push_back(new LootChest(row, col));
            }
            else if (tileAsString == "l") {
                Levelchanger* levelchanger = new Levelchanger(row, col);
                tilepointer[row].push_back(levelchanger);
                levelchangers.push_back(levelchanger);
            }
            else {
                Floor* new_floor = new Floor(row, col);
                tilepointer[row].push_back(new_floor);

                if (tileAsString == "X") {
                    Character* new_character = new Character(100, 100, 20, true); //immer hier die stats ändern
                    placeCharacter(new_character, row, col);

                    characterpointer.push_back(new_character);
                }
                else if (tileAsString == "N") {
                    Character* newNpc = new Character(200, 2, 2, false);
                    //Controller* npcController = new GuardController({4, 4, 2, 6, 6, 6});
                    Controller* npcController = new Attackcontroller(this, newNpc);
                    newNpc->setController(npcController);

                    placeCharacter(newNpc, row, col);

                    characterpointer.push_back(newNpc);
                }
            }
        }
    }
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

void Level::deleteCharacterById(int id) {
    for (unsigned i = 0; i < characterpointer.size(); i++) {
        if (characterpointer[i]->getId() == id) {
            characterpointer[i]->getTile()->setCharacter(nullptr);
            characterpointer.erase(characterpointer.begin() + i);
        }
    }
}
