#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "tile.h"
#include "active.h"
#include "level.h"

class Character;

class Levelchanger : public Tile, public Active
{
public:
    Levelchanger(int row, int col);
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile *destTile, Character *who) override;

private:
    Level* destinationLevel;
};

#endif // LEVELCHANGER_H
