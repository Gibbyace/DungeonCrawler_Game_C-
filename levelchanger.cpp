#include "levelchanger.h"
#include "character.h"

Levelchanger::Levelchanger(int row, int col) : Tile(row, col)
{

}

Tile* Levelchanger::onEnter(Tile *fromTile, Character *who) {
    if (who->getIsPlayerCharacter()) {
        activate();
    }

    return this;
}

Tile* Levelchanger::onLeave(Tile *destTile, Character *who) {
    return this;
}

void Levelchanger::setDestinationLevel(Level *level)
{
    destinationLevel = level;
}

Level *Levelchanger::getDestinationLevel() const
{
    return destinationLevel;
}

int Levelchanger::getDestinationLevelId() const
{
    return destinationLevelId;
}

void Levelchanger::setDestinationLevelId(int newDestinationLevelId)
{
    destinationLevelId = newDestinationLevelId;
}
