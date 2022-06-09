#ifndef RAMP_H
#define RAMP_H

#include "tile.h"

class Ramp : public Tile
{
public:
    Ramp(int row, int column);
    virtual ~Ramp() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;



};

#endif // RAMP_H
