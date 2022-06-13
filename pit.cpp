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
    if (dynamic_cast<Pit*>(destTile) != nullptr || dynamic_cast<Ramp*>(destTile) != nullptr) {
        return this;
    }

    return nullptr;
}
