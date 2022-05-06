#include "portal.h"
#include "tile.h"

Portal::Portal(int row, int col) : Tile(row, col)
{
    this->texture = "O";
}

Tile* Portal::onEnter(Tile *fromTile, Character *who) {
    return this;
}

Tile* Portal::onLeave(Tile* destTile, Character* who) {
    //TODO: anstelle von this Zeiger der verundenen Kachel zurückgeben
    return this;
}
