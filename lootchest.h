#ifndef LOOTCHEST_H
#define LOOTCHEST_H

#include "tile.h"

class LootChest : public Tile
{
public:
    LootChest();
    LootChest(int row, int col);
    virtual ~LootChest() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // LOOTCHEST_H
