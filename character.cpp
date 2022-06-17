#include "character.h"

int Character::idCounter = 0;

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

int Character::getStrength() const
{
    return strength;
}

int Character::getStamina() const
{
    return stamina;
}

int Character::getHitpoints() const
{
    return hitpoints;
}

bool Character::getIsPlayerCharacter() const
{
    return isPlayerCharacter;
}

void Character::setIsPlayerCharacter(bool value)
{
    isPlayerCharacter = value;
}

int Character::getId() const
{
    return id;
}

Character::Character(int strength, int stamina, int hitpoints, bool isPlayerCharacter)
{
    idCounter++;

    this->id = idCounter;
    this->strength = strength;
    this->stamina = stamina;
    this->hitpoints = hitpoints;
    this->isPlayerCharacter = isPlayerCharacter;
}

int Character::move() {
    moveDirection = controller->move();
    return moveDirection;
}
