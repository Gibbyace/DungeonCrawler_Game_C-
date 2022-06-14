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

int Character::getMoveDirection() const
{
    return moveDirection;
}

int Character::getMaxHP() {
    return 20 + (stamina + 5);
}

Character::Character(int strength, int stamina, int hitpoints)
{
    this->strength = strength;
    this->stamina = stamina;
    this->hitpoints = hitpoints;
}

int Character::move() {
    moveDirection = controller->move();

    return moveDirection;
}
