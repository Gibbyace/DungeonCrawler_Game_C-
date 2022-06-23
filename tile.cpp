#include "tile.h"
#include "character.h"

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

Character *Tile::getCharacter() const
{
    return character;
}

Tile::Tile(const int row, const int column) : row(row), column(column)
{

}

string Tile::getTexture(){
    if (this->hasCharacter() == true) {
        return "@";
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


    if (destTile->hasCharacter() && who->getTile() != destTile) {
        std::cout<<"Hey du Arschgesicht ";
        battle(destTile, who);
    }
    else {
        who->setTile(enteredTile);
        this->character = nullptr;
        enteredTile->setCharacter(who);
    }

    return true;
}

void Tile::battle(Tile *destTile, Character *who) {

    int damage = character->getStrength();
    destTile->getCharacter()->setHitpoints(destTile->getCharacter()->getHitpoints() - damage);
}
