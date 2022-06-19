#include "lootchest.h"

LootChest::LootChest(int row, int col) : Tile (row, col)
{
    this->texture = "e";
}



Tile *LootChest::onEnter(Tile *fromTile, Character *who)
{
    return this;
}

Tile *LootChest::onLeave(Tile *destTile, Character *who)
{
    return this;
}
