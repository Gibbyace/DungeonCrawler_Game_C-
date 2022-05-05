#include "level.h"
#include <vector>
#include <string>
#include "portal.h"
#include "floor.h"
#include "wall.h"
#include "tile.h"

Level::Level(const int height, const int width):height(height),width(width)
{
    vector<vector<string>> level_as_string =
        {
            {"#", "#", "#", "#", "#", "#"},
            {"#", ".", ".", "O", ".", "#"},
            {"#", "X", ".", ".", ".", "#"},
            {"#", ".", ".", ".", ".", "#"},
            {"#", ".", "O", ".", ".", "#"},
            {"#", "#", "#", "#", "#", "#"}
        };

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (level_as_string[i][j] == "#") {

               Tile* level_as_string[i][j] = new Wall(int row, int column,string texture);
                tilepointer.push_back()
            }
            else if (level_as_string[i][j] == "O") {
               string texture = "O";
               Tile* new_portal = new Portal(i , j ,texture);
               tilepointer.push_back(new_portal);

            }
            else {
                level_as_string[i][j] = new Floor(int row, int column,string texture);

                if (level_as_string[i][j] == "X") {
                    Character* new_character = new Character(); //hier kommt der Floorpointer noch rein

                    characterpointer.push_back(new_character);
                    level_as_string[i][j]. //Dem floor wird character zugewisen
                }
            }
        }
    }
}
