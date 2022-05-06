#ifndef FLOOR_H
#define FLOOR_H

#include "tile.h"

class Floor : public Tile
{
public:
    Floor(int row, int col);
    virtual ~Floor() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // FLOOR_H
