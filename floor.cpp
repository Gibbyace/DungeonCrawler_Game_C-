#include "floor.h"
#include "tile.h"

Floor::Floor(int row, int col) : Tile (row, col)
{
    this->texture = ".";
}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Floor::onLeave(Tile *destTile, Character *who)
{
    return this;
}

