#ifndef LEVEL_H
#define LEVEL_H
#include "character.h"
#include "tile.h"
#include <vector>

using namespace std;

class Level
{
    vector<vector<Tile*>> tilepointer; //TODO: tilepointer als vector von vectoren initialisieren im Konstruktur; Schleife für erstellen von level, dann pushback
    vector<Character*> characterpointer;
    const int height;
    const int width;


public:
    Level(const int height, const int width);
    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;
    void placeCharacter(Character *c, int row, int col);
};

#endif // LEVEL_H
