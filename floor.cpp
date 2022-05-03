#include "floor.h"
#include "tile.h"

Floor::Floor(int row, int col, string texture) : Tile (row, col)
{
        this->texture=texture; //Bekommt texture von terminalui generator


}

Tile *Floor::onEnter(Tile *fromTile, Character *who)
{


}

Tile *Floor::onLeave(Tile *destTile, Character *who)
{
    //nicht vergessen: wenn Methode leer und erbt, dann abstrakt; Bitte ausprogrammieren
}

