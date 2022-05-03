#include "wall.h"
#include "tile.h"

Wall::Wall(int row, int column,string texture) : Tile(row, column)
{
    this->texture=texture;


}
