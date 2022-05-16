#ifndef SWITCH_H
#define SWITCH_H

#include "active.h"
#include "tile.h"

class Switch : public Active, public Tile
{
public:
    Switch();
    Tile* onEnter(Tile* from, Character* who);
};

#endif // SWITCH_H
