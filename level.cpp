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
                    new_character->setTile(new_floor);
                    new_floor->setCharacter(new_character);

                    characterpointer.push_back(new_character);
                }
            }
        }
    }
}
