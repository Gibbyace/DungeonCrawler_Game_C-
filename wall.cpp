#include "wall.h"
#include "tile.h"

Wall::Wall(int row, int column,string texture) : Tile(row, column)
{
    this->texture=texture;


}

Tile* Wall::onEnter(Tile *fromTile, Character *who) {

}

Tile* Wall::onLeave(Tile* destTile, Character* who) {

}
