#include "portal.h"
#include "tile.h"

Portal::Portal(int row, int col) : Tile(row, col)
{
    this->texture = "O";
}

Tile *Portal::getDestination() const
{
    return destination;
}

void Portal::setDestination(Tile *newDestination)
{
    destination = newDestination;
}

Tile* Portal::onEnter(Tile *fromTile, Character *who) {
    return destination;
}

Tile* Portal::onLeave(Tile* destTile, Character* who) {
    return this;
}

