#include "ramp.h"

Ramp::Ramp(int row, int column): Tile(row, column)
{
    this->texture = "<";
}



Tile *Ramp::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Ramp::onLeave(Tile *destTile, Character *who)
{
    return this;
}
