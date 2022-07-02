#include "portal.h"
#include "tile.h"

int Portal::getRow() const
{
    return row;
}

int Portal::getCol() const
{
    return col;
}

Portal::Portal(int row, int col) : Tile(row, col)
{
    this->texture = "O";
    this->row = row;
    this->col = col;
}

Portal::~Portal() {
    delete destination;
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
    /*if (fromTile == this) {
        return this;
    }*/

    return destination;
}

Tile* Portal::onLeave(Tile* destTile, Character* who) {
    return this;
}

