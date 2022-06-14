#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
#include <controller.h>

using namespace std;

class Tile;

class Character
{
private:
    string texture;
    int moveDirection = 2;
    Tile* tile;
    Controller* controller;
    int strength;
    int stamina;
    int hitpoints;

public:
    Character(int strength, int stamina, int hitpoints);
    int move();
    const string &getTexture() const;
    void setTile(Tile *newTile);
    Tile *getTile() const;
    void setController(Controller *value);
    int getMoveDirection() const;
    int getMaxHP();
};

#endif // CHARACTER_H
