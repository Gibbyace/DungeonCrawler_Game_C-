#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>

using namespace std;

class Tile;

class Character
{
    string texture;
    Tile* tile; //Setter wird gebraucht



public:
    Character();
    //int move();

    const string &getTexture() const;
    void setTile(Tile *newTile);
    Tile *getTile() const;
};

#endif // CHARACTER_H
