#ifndef PORTAL_H
#define PORTAL_H

#include "tile.h"

class Portal : public Tile
{
public:
    Portal(int row, int col, string texture);
    virtual ~Portal() override = default;
};

#endif // PORTAL_H
