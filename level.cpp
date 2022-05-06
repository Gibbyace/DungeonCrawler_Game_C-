#include "level.h"
#include <vector>
#include <string>
#include "portal.h"
#include "floor.h"
#include "wall.h"
#include "tile.h"

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

    vector<vector<string>> level_as_string =
        {
            {"#", "#", "#", "#", "#", "#"},
            {"#", ".", ".", "O", ".", "#"},
            {"#", "X", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", "#"},
            {"#", ".", "O", ".", ".", "#"},
            {"#", "#", "#", "#", "#", "#"}
        };

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (level_as_string[row][col] == "#") {
                tilepointer[row].push_back(new Wall(row, col, "#"));
            }
            else if (level_as_string[row][col] == "O") {
               tilepointer[row].push_back(new Portal(row, col, "O"));
            }
            else {
                Floor* new_floor = new Floor(row, col, ".");
                tilepointer[row].push_back(new_floor);

                if (level_as_string[row][col] == "X") {
                    Character* new_character = new Character();
                    placeCharacter(new_character, row, col);

                    characterpointer.push_back(new_character);
                }
            }
        }
    }
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
