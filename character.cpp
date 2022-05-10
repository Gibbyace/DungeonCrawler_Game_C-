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

Character::Character()
{

}

int Character::move(){
    while (true) {
        char input;

        cin >> input;

        if (input >= 48 && input <= 58) {
            return input - 48;
        }
        else {
            cout << "This is not an option" << endl << endl;
            return 5;
        }


    }
}
