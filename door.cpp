#include "door.h"

Door::Door(int row, int column): Passive(), Tile(row, column)
{
    this->texture = "X";
}



void Door::notify(Active *source){
    if (this->texture == "X") {
        this->texture = "/";
    }
    else {
        this->texture = "X";
    }
}

Tile* Door::onEnter(Tile *fromTile, Character *who){
    if (this->texture == "X") {
        return nullptr;
    }

    return this;
}

Tile* Door::onLeave(Tile *destTile, Character *who){
    return this;
}
