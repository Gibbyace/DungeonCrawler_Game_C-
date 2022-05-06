#ifndef PORTAL_H
#define PORTAL_H

#include "tile.h"

class Portal : public Tile
{
private:
    Tile* destination;

public:
    Portal(int row, int col);
    virtual ~Portal() override = default;
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    //TODO: Verweis auf das dazugehörige Portal
    Tile *getDestination() const;
    void setDestination(Tile *newDestination);
};

#endif // PORTAL_H
