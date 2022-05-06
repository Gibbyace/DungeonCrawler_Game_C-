#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>


class Tile;

class Character
{
    std::string texture_of_character;
    Tile* tile; //Setter wird gebraucht



public:
    Character();
    int move();

    const std::string &getTexture_of_character() const;
    void setTexture_of_character(const std::string &newTexture_of_character);
    void setTile(Tile *newTile);
};

#endif // CHARACTER_H
