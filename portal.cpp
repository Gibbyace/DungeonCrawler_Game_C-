﻿#include "portal.h"
#include "tile.h"

Portal::Portal(int row, int col,string texture) : Tile(row, col)
{
    this->texture=texture;

}
