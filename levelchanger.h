#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "tile.h"
#include "active.h"

class Levelchanger : public Tile, public Active
{
public:
    Levelchanger(int row, int col);
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile *destTile, Character *who) override;
};

#endif // LEVELCHANGER_H
