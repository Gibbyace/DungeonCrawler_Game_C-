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
        //TODO: Absichern, dass sich keine Spieler gegenseitig und keine NPCs gegenseitig kloppen
        battle(who, destTile->getCharacter());
    }
    else {
        who->setTile(enteredTile);
        this->character = nullptr;
        enteredTile->setCharacter(who);
    }

    return true;
}

void Tile::battle(Character* attacker, Character* defender) {
    cout << endl << attacker->getId() << " greift " << defender->getId() << " an." << endl;
    cout << "Angreifer HP: " << attacker->getHitpoints() << endl;
    cout << "Verteidig HP: " << defender->getHitpoints() << endl;

    int attackerDamage = attacker->getStrength();
    defender->setHitpoints(defender->getHitpoints() - attackerDamage);

    if (defender->getHitpoints() > 0) {
        int defenderDamage = defender->getStrength();
        attacker->setHitpoints(attacker->getHitpoints() - defenderDamage);
    }

    cout << "Angreifer HP nachher: " << attacker->getHitpoints() << endl;
    cout << "Verteidig HP nachher: " << defender->getHitpoints() << endl;
}
