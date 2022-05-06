#include "tile.h"
#include "character.h"
#include <string>

#include "floor.h"
#include "wall.h"
#include "portal.h"

void Tile::setCharacter(Character *newCharacter)
{
    character = newCharacter;
}

int Tile::getRow() const
{
    return row;
}

int Tile::getColumn() const
{
    return column;
}

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

    return true;
}

bool Tile::moveTo(Tile *destTile, Character *who){
    Tile* fromTile = this->onLeave(destTile, who);

    if (fromTile == nullptr) {
        return false;
    }

    Tile* enteredTile = destTile->onEnter(fromTile, who);

    if (enteredTile == nullptr) {
        return false;
    }

    who->setTile(enteredTile);
    this->character = nullptr;
    enteredTile->setCharacter(who);

    return true;
}


