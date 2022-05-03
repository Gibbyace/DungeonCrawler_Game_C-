#ifndef FLOOR_H
#define FLOOR_H

#include "tile.h"

class Floor : public Tile
{
public:
    Floor(int row, int col, string texture);
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
    virtual ~Floor() override = default; //override?
};

#endif // FLOOR_H
