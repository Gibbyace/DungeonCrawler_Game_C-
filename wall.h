#ifndef WALL_H
#define WALL_H

#include "tile.h"
#include <string>
using namespace std;

class Wall : public Tile
{
public:
    Wall(int row, int column,string texture);
    virtual ~Wall() override = default;

private:
    string texture;
    Character* character;
};

#endif // WALL_H
