#include "graph.h"

Graph::Graph(Level* level)
{
    this->level = level;
    //generiert adjacencyList basierend auf Tilepointer des Levels
}

vector<Tile*> Graph::getPath(Tile *from, Tile *to, int traveledDistance) {
    vector<Tile*> path;

    map<Tile*, tuple<int, Tile*, bool>> nodes = initializeDijkstra(from); //das könnte man zu nem Attribut machen

    vector<Tile*> neighbours = neighboursFrom(from);

    //speichern, dass from besucht wurde
    nodes[from] = {get<0>(nodes[from]), get<1>(nodes[from]), true};

    traveledDistance += 1;

    for (auto neighbour : neighbours) {
        bool nodeHasBeenVisited = get<2>(nodes[neighbour]);
        if (!nodeHasBeenVisited) {
            int shortestDistance = get<0>(nodes[neighbour]);

            if (traveledDistance < shortestDistance || shortestDistance == -1) {
                get<0>(nodes[neighbour]) = traveledDistance;
                get<1>(nodes[neighbour]) = from;
            }
        }
    }

    /*
    nachbarn = neighboursFrom(from)

    speichern dass from besucht wurde

    irgendwie bisherige Distanz vergleichen und ggf. Speichern

    traveledDistance += 1

    for (nachbar of nachbarn) {
        if (nachbar noch nicht besucht) {
            getPath(nachbar, to, traveledDistance) //nodes mit übergeben?
        }
    }

    Abbruchbedingung? Vielleicht ist keine notwendig
    */

    return path;
}

map<Tile*, tuple<int, Tile*, bool>> Graph::initializeDijkstra(Tile* from) {
    map<Tile*, tuple<int, Tile*, bool>> nodes;

    vector<vector<Tile*>> levelTilePointer = level->getTilepointer();

    for (unsigned row = 0; row < levelTilePointer.size(); row++) {
        for (unsigned col = 0; col < level->getTilepointer()[row].size(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];

            if (currentTile != from) {
                nodes[currentTile] = {-1, nullptr, false};
            }
            else {
                nodes[currentTile] = {0, nullptr, true};
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
