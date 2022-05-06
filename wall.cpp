#include "wall.h"
#include "tile.h"

Wall::Wall(int row, int column) : Tile(row, column)
{
    this->texture = "#";
}

Tile* Wall::onEnter(Tile *fromTile, Character *who) {
    return nullptr;
}

Tile* Wall::onLeave(Tile* destTile, Character* who) {
    return this;
}
