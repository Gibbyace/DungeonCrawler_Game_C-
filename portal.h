#ifndef PORTAL_H
#define PORTAL_H

#include "tile.h"

class Portal : public Tile
{
private:
    Tile* destination;
    int row;
    int col;

public:
    Portal(int row, int col);
    virtual ~Portal() override;
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile* destTile, Character* who) override;

    Tile* getDestination() const;
    void setDestination(Tile *newDestination);
    int getRow() const;
    int getCol() const;
};

#endif // PORTAL_H
