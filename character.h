#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "tile.h" //kann löschen, wenn include loop
#include <iostream>


class Tile;

class Character
{
    std::string texture_of_character;
    Tile* tile; //Setter wird gebraucht



public:
    Character();
    int move();

};

#endif // CHARACTER_H
