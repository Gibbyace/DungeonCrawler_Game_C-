#include "floor.h"
#include "tile.h"

Floor::Floor(int row, int col, string texture) : Tile (row, col)
{
        this->texture=texture; //Bekommt texture von terminalui generator


}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *Floor::onLeave(Tile *destTile, Character *who) //Bin mir jetzt nicht sicher, ob das this oder destTile zurückgeben soll
{
    return this;
}

