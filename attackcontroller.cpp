#include "attackcontroller.h"
#include "portal.h"

Attackcontroller::Attackcontroller(Level* level, Character* controllingCharacter) {
    this->level = level;
    this->controllingCharacter = controllingCharacter;
    this->graph = new Graph(level);
}

int Attackcontroller::move() {
    Tile* controllingCharacterTile = controllingCharacter->getTile();
    Tile* followingCharacterTile = getTileWithPlayerCharacter();

    list<Tile*> path = graph->getPath(controllingCharacterTile, followingCharacterTile);

    if (path.size() == 0) {
        return 5;
    }

    Tile* destinationTile = path.front();

    /*if (path.front() == controllingCharacterTile && dynamic_cast<Portal*>(path.front()) != nullptr) {
        destinationTile = path.front();
    }
    else {
        destinationTile = *std::next(path.begin());
    }*/

    pair<int, int> controllingCharacterPosition = {
        controllingCharacterTile->getRow(),
        controllingCharacterTile->getColumn()
    };

    pair<int, int> destinationTilePosition = {
        destinationTile->getRow(),
        destinationTile->getColumn()
    };

    if (controllingCharacterPosition.first < destinationTilePosition.first) {
        //controllingCharacter muss nach unten

        if (controllingCharacterPosition.second < destinationTilePosition.second) {
            return 3;
        }
        else if (controllingCharacterPosition.second == destinationTilePosition.second) {
            return 2;
        }
        else if (controllingCharacterPosition.second > destinationTilePosition.second) {
            return 1;
        }
    }
    else if (controllingCharacterPosition.first == destinationTilePosition.first) {
        //controllingCharacter bleibt in der gleichen Reihe

        if (controllingCharacterPosition.second < destinationTilePosition.second) {
            return 6;
        }
        else if (controllingCharacterPosition.second == destinationTilePosition.second) {
            return 5;
        }
        else if (controllingCharacterPosition.second > destinationTilePosition.second) {
            return 4;
        }
    }
    else if (controllingCharacterPosition.first > destinationTilePosition.first) {
        //controllingCharacter muss nach oben

        if (controllingCharacterPosition.second < destinationTilePosition.second) {
            return 9;
        }
        else if (controllingCharacterPosition.second == destinationTilePosition.second) {
            return 8;
        }
        else if (controllingCharacterPosition.second > destinationTilePosition.second) {
            return 7;
        }
    }

    return 5;
}


Tile *Attackcontroller::getTileWithPlayerCharacter()
{
    for (auto row : level->getTilepointer()) {
        for (auto tile : row) {
            if (tile->hasCharacter() && tile->getCharacter()->getIsPlayerCharacter()) {
                return tile;
            }
        }
    }

    return nullptr;
}
