#include "character.h"
#include <string>

const string &Character::getTexture() const
{
    return texture;
}

void Character::setTile(Tile *newTile)
{
    tile = newTile;
}

Tile *Character::getTile() const
{
    return tile;
}

void Character::setController(Controller *value)
{
    controller = value;
}

Character::Character()
{

}

int Character::move() {
    return controller->move();
}
