#include "levelchanger.h"

Levelchanger::Levelchanger(int row, int col) : Tile(row, col)
{

}

Tile* Levelchanger::onEnter(Tile *fromTile, Character *who) {
    return this;
}

Tile* Levelchanger::onLeave(Tile *destTile, Character *who) {
    return this;
}
