#include "door.h"

Door::Door(int row, int column): Passive(), Tile(row, column)
{

}



void Door::notify(Active *source){

}

Tile* Door::onEnter(Tile *fromTile, Character *who){
    return this;//TODO: Muss geändert werden, warscheinlich was mit switch und notify
}

Tile* Door::onLeave(Tile *destTile, Character *who){
    return this;//TODO: Muss man auch ändern
}
