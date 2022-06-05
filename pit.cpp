#include "pit.h"
#include "ramp.h"
#include <typeinfo>

Pit::Pit(int row, int column): Tile(row, column)
{
    this->texture = "_";

}

Tile *Pit::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Pit::onLeave(Tile *destTile, Character *who)
{
    if ((typeid(*destTile) == typeid(Pit)) or (typeid(*destTile) == typeid(Ramp))){
        return this;
    }

    return nullptr;
}
