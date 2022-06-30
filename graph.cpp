#include "graph.h"

Graph::Graph(Level* level)
{
    this->level = level;
    //generiert adjacencyList basierend auf Tilepointer des Levels
}

vector<Tile*> Graph::getPath(Tile *from, Tile *to, int traveledDistance) {
    vector<Tile*> path;

    map<Tile*, pair<int, Tile*>> nodes = initializeDijkstra(from);

    vector<Tile*> neighbours = neighboursFrom(from);

    /*
    nachbarn = neighboursFrom(from)

    speichern dass from besucht wurde
    irgendwie bisherige Distanz vergleichen und ggf. Speichern

    traveledDistance += 1

    for (nachbar of nachbarn) {
        if (nachbar noch nicht besucht) {
            getPath(nachbar, to, traveledDistance)
        }
    }

    Abbruchbedingung? Vielleicht ist keine notwendig
    */

    return path;
}

map<Tile*, pair<int, Tile*>> Graph::initializeDijkstra(Tile* from) {
    map<Tile*, pair<int, Tile*>> nodes;

    vector<vector<Tile*>> levelTilePointer = level->getTilepointer();

    for (unsigned row = 0; row < levelTilePointer.size(); row++) {
        for (unsigned col = 0; col < level->getTilepointer()[row].size(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];

            if (currentTile != from) {
                nodes[currentTile] = {-1, nullptr};
            }
            else {
                nodes[currentTile] = {0, nullptr};
            }
        }
    }

    return nodes;
}

vector<Tile *> Graph::neighboursFrom(Tile *tile)
{
    vector<Tile*> neighbours;
    vector<vector<Tile*>> tiles = level->getTilepointer();
    int row = tile->getRow();
    int col = tile->getColumn();

    vector<pair<int, int>> relativeNeighbourPositions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };

    for (unsigned i = 0; i < relativeNeighbourPositions.size(); i++) {
        int neighbourRow = row + relativeNeighbourPositions[i].first;
        int neighbourCol = col + relativeNeighbourPositions[i].second;

        if (neighbourCol < 0 || neighbourRow < 0) {
            continue;
        }

        Tile* neighbourTile = tiles[neighbourRow][neighbourCol];
        bool neighbourTileIsEnterable = false;

        Character dummyCharacter = Character(10, 10, 10, false);

        //TODO: ACHTUNG, DAS HAT SEITENEFFEKTE!
        //TODO: Portale
        Tile* fromTile = tile->onLeave(neighbourTile, &dummyCharacter);
        Tile* enteredTile = neighbourTile->onEnter(fromTile, &dummyCharacter);

        if (fromTile != nullptr && enteredTile != nullptr) {
            neighbourTileIsEnterable = true;
            neighbours.push_back(neighbourTile);
        }
    }

    return neighbours;
}
