#include "pit.h"
#include "ramp.h"

Pit::Pit(int row, int column): Tile(row, column)
{
    this->texture = "_";

}
Tile *Pit::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Pit::onLeave(Tile *destTile, Character *who) //Müssen *destile implementieren und dann mit typeid bestimmen
{
    if ((typeid(*destTile) == typeid(Pit)) or (typeid(*destTile) == typeid(Ramp))){
        return this;
    }
    else
        return nullptr;

}
