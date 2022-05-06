#ifndef PORTAL_H
#define PORTAL_H

#include "tile.h"

class Portal : public Tile
{
public:
    Portal(int row, int col, string texture);
    virtual ~Portal() override = default;
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    //TODO: Verweis auf das dazugehörige Portal
};

#endif // PORTAL_H
