#include "tile.h"
#include "character.h"
#include <string>

#include "floor.h"
#include "wall.h"
#include "portal.h"

Tile::Tile(const int row, const int column):row(row),column(column)
{

}

std::string Tile::getTexture(){
    if (this->hasCharacter() == true) {
        return "X";
    }

    return texture;
}

bool Tile::hasCharacter(){
    if (character == nullptr) {
        return false;
    }
    else {
        return true;
    }
}

bool Tile::moveTo(Tile *fromTile, Character *who){
    //HOW?
}


