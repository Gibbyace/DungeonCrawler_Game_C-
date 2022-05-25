#ifndef DOOR_H
#define DOOR_H

#include "passive.h"
#include "tile.h"


class Door : public Passive, public Tile
{
public:
    Door(int row, int column);
    virtual void notify(Active* source) override;
    virtual ~Door() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // DOOR_H
