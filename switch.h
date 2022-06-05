#ifndef SWITCH_H
#define SWITCH_H

#include "active.h"
#include "tile.h"

class Switch : public Active, public Tile
{
public:
    Switch(int row, int column);
    virtual Tile* onEnter(Tile* from, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
    virtual ~Switch() override = default;
};

#endif // SWITCH_H
