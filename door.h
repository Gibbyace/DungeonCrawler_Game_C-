#ifndef DOOR_H
#define DOOR_H

#include "passive.h"
#include "tile.h"

class Door : public Passive, public Tile
{
public:
    Door(int row, int column);
};

#endif // DOOR_H
