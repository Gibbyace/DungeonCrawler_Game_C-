#ifndef LEVEL_H
#define LEVEL_H
#include "character.h"
#include "tile.h"
#include <vector>

using namespace std;

class Level
{
    vector<vector<Tile*>> tilepointer;
    vector<Character*> characterpointer;
    const int height;
    const int width;


public:
    Level(const int height, const int width);
    ~Level();
    Tile *getTile(int row, int col);
    const Tile *getTile(int row, int col) const;
    const vector<vector<Tile *> > &getTilepointer() const;
    int getHeight() const;
    int getWidth() const;
    const vector<Character *> &getCharacterpointer() const;

protected:
    void placeCharacter(Character *c, int row, int col);
    void placePortals(int row1, int col1, int row2, int col2);
};

#endif // LEVEL_H
