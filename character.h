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
    int id;
    string texture;
    int moveDirection = 2;
    Tile* tile;
    Controller* controller;
    int strength;
    int stamina;
    int hitpoints;
    bool isPlayerCharacter;

public:
    Character(int strength, int stamina, int hitpoints, bool isPlayerCharacter);
    ~Character();
    int move();
    const string &getTexture() const;
    void setTile(Tile *newTile);
    Tile *getTile() const;
    void setController(Controller *value);
    int getMoveDirection() const;
    int getMaxHP();
    int getStrength() const;
    int getStamina() const;
    int getHitpoints() const;
    bool getIsPlayerCharacter() const;
    void setIsPlayerCharacter(bool value);

    static int idCounter;
    int getId() const;
    void setHitpoints(int newHitpoints);
};

#endif // CHARACTER_H
