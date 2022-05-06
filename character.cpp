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
        int input;

        cout << "Where do you want to go?" << endl;
        cout << "1: Down-Right" << endl;
        cout << "2: Down" << endl;
        cout << "3: Down-Right" << endl;
        cout << "4: Left" << endl;
        cout << "5: Stay" << endl;
        cout << "6: Right" << endl;
        cout << "7: Left-Up" << endl;
        cout << "8: Up" << endl;
        cout << "9: Up-Right" << endl;
        cout << "0: Close Game" << endl;
        cout << endl;

        cin >> input;

        if (input >= 0 && input <= 9) {
            return input;
        }

        cout << "This is not an option" << endl;
    }
}
