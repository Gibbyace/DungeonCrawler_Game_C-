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
    Tile* tile;
    Controller* controller;

public:
    Character();
    int move();
    const string &getTexture() const;
    void setTile(Tile *newTile);
    Tile *getTile() const;
    void setController(Controller *value);
};

#endif // CHARACTER_H
