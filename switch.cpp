#include "switch.h"

Switch::Switch(int row, int column): Active(), Tile(row, column)
{
    this->texture = "?";
}

Tile* Switch::onEnter(Tile *fromTile, Character *who){
    this->activate();

    return this;
}
Tile* Switch::onLeave(Tile *destTile, Character *who){
    return this;
}
