#ifndef PIT_H
#define PIT_H

#include "tile.h"

class Pit : public Tile
{
public:
    Pit(int row, int column);
    virtual ~Pit() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;

};

#endif // PIT_H
