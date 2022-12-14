#ifndef LEVELCHANGER_H
#define LEVELCHANGER_H

#include "tile.h"
#include "active.h"
#include "level.h"

class Character;

class Level;

class Levelchanger : public Tile, public Active
{
public:
    Levelchanger(int row, int col);
    virtual ~Levelchanger() override = default;
    Tile* onEnter(Tile *fromTile, Character *who) override;
    Tile* onLeave(Tile *destTile, Character *who) override;

    void setDestinationLevel(Level *value);

    Level *getDestinationLevel() const;

    int getDestinationLevelId() const;
    void setDestinationLevelId(int newDestinationLevelId);

private:
    int destinationLevelId;
    Level* destinationLevel;
};

#endif // LEVELCHANGER_H
