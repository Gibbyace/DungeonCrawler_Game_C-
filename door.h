#ifndef DOOR_H
#define DOOR_H

#include "passive.h"
#include "tile.h"

//TODO: isOpen muss sich irgendwie zur laufzeit ändern;

class Door : public Passive, public Tile
{
private:
    bool isOpen = false;

public:
    Door(int row, int column);
    virtual void notify(Active* source) override;
    virtual ~Door() override = default;
    virtual Tile *onEnter(Tile* fromTile, Character* who) override;
    virtual Tile* onLeave(Tile* destTile, Character* who) override;
};

#endif // DOOR_H
