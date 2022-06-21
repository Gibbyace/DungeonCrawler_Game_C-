#include "levelchanger.h"
#include "character.h"

Levelchanger::Levelchanger(int row, int col) : Tile(row, col)
{

}

Tile* Levelchanger::onEnter(Tile *fromTile, Character *who) {
    //if (who)
    cout << "Ich wurde betreten" << endl;
    activate();
    if (who->getIsPlayerCharacter()) {
        activate();
    }
    return this;
}

Tile* Levelchanger::onLeave(Tile *destTile, Character *who) {
    return this;
}
