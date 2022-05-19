#include "switch.h"

Switch::Switch(int row, int column): Active(), Tile(row, column)
{
    this->texture = "?";
}

Tile* Switch::onEnter(Tile *fromTile, Character *who){
    return this; //TODO: Muss geändert werden, sehr warscheinlich
}
Tile* Switch::onLeave(Tile *destTile, Character *who){
    return this;//TODO: Also this muss geändert werden
}
