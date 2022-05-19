#include "level.h"
#include <vector>
#include <string>
#include "portal.h"
#include "floor.h"
#include "wall.h"
#include "tile.h"
#include "switch.h"
#include "door.h"

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

const vector<Character *> &Level::getCharacterpointer() const
{
    return characterpointer;
}

Level::Level(const int height, const int width):height(height),width(width)
{
    for (int i = 0; i < height; i++) {
        vector<Tile*> row = vector<Tile*>();
        tilepointer.push_back(row);
    }

    //Wir können hier nicht einfach Portals reinschreiben, weil wir es sonst nicht hinbekommen, das sie aufeinander verweisen
    //Daher placePortals() benutzen
    vector<vector<string>> level_as_string =
        {
            {"#", "#", "#", "#", "#", "#"},
            {"#", ".", ".", "#", ".", "#"},
            {"#", ".", ".", "#", ".", "#"},
            {"#", ".", "X", "#", ".", "#"},
            {"#", ".", ".", "#", ".", "#"},
            {"#", "#", "#", "#", "#", "#"}
        };

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            string tileAsString = level_as_string[row][col];

            if (tileAsString == "#") {
                tilepointer[row].push_back(new Wall(row, col));
            }
            else {
                Floor* new_floor = new Floor(row, col);
                tilepointer[row].push_back(new_floor);

                if (tileAsString == "X") {
                    Character* new_character = new Character();
                    placeCharacter(new_character, row, col);

                    characterpointer.push_back(new_character);
                }
            }
        }
    }

    placePortals(1, 1, 4, 1);
    placePortals(4, 4, 1, 4);

}

Level::~Level() {
    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            delete tilepointer[row][col];
        }
    }

    for (unsigned i = 0; i < characterpointer.size(); i++) {
        delete characterpointer[i];
    }
}

Tile* Level::getTile(int row, int col) {
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

void Level::placeSwitch(int row1, int col1, int row2, int col2) {
    Tile* newSwitch = new Switch(row1, col1);
    Tile* newDoor = new Door(row2, col2);
}
