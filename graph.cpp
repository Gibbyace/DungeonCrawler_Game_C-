#include "graph.h"
#include "wall.h"
#include <iomanip>

Graph::Graph(Level* level)
{
    this->level = level;
    //generiert adjacencyList basierend auf Tilepointer des Levels, vielleicht auch nicht
}

vector<Tile*> Graph::getPath(Tile *from, Tile *to) {
    vector<Tile*> path;

    map<Tile*, tuple<int, Tile*, bool>> nodes = initializeDijkstra(from); //das könnte man zu nem Attribut machen

    nodes = executeDijkstra(from, nodes);

    return path;
}

map<Tile*, tuple<int, Tile*, bool>> Graph::executeDijkstra(Tile* from, map<Tile*, tuple<int, Tile*, bool>> nodes) {
    cout << endl << "Looking at: " << from->getRow() << " " << from->getColumn() << endl << endl;

    vector<Tile*> neighbours = neighboursFrom(from);

    //speichern, dass from besucht wurde
    nodes[from] = {get<0>(nodes[from]), get<1>(nodes[from]), true};

    printNodes(nodes);

    if (neighbours.size() == 0) {
        return nodes;
    }

    //Distanzen zu den Nachbarn updaten
    for (auto neighbour : neighbours) {
        int shortestDistanceToThisNeighbourYet = get<0>(nodes[neighbour]);

        if (get<0>(nodes[from]) < shortestDistanceToThisNeighbourYet || shortestDistanceToThisNeighbourYet == -1) {
            get<0>(nodes[neighbour]) = get<0>(nodes[from]) + 1;
            get<1>(nodes[neighbour]) = from;
        }
    }

    vector<Tile*> unvisitedNeighbours = filterOutVisitedTiles(neighbours, nodes);

    while (unvisitedNeighbours.size() > 0) {
        int shortestDistance = get<0>(nodes[unvisitedNeighbours[0]]);
        Tile* unvisitedNeighbourWithShortestDistance = unvisitedNeighbours[0];
        int indexOfTileWithShortestDistance = 0;

        for (unsigned i = 0; i < unvisitedNeighbours.size(); i++) {
            Tile* neighbour = unvisitedNeighbours[i];

            if (get<0>(nodes[neighbour]) < shortestDistance && get<0>(nodes[neighbour]) != -1) {
                shortestDistance = get<0>(nodes[neighbour]);
                unvisitedNeighbourWithShortestDistance = neighbour;
                indexOfTileWithShortestDistance = i;
            }
        }

        unvisitedNeighbours.erase(unvisitedNeighbours.begin() + indexOfTileWithShortestDistance);

        //mach weiter mit dem unbesuchten Nacharn mit dem niedrigsten Wert
        nodes = executeDijkstra(unvisitedNeighbourWithShortestDistance, nodes);
    }

    return nodes;
}

void Graph::printNodes(map<Tile *, tuple<int, Tile *, bool>>& nodes) {
    for (unsigned row = 0; row < level->getTilepointer().size(); row++) {
        for (unsigned col = 0; col < level->getTilepointer()[row].size(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];
            std::cout.width(5);

            cout << get<0>(nodes[currentTile]);
        }

        cout << endl;
    }

    cout << endl;
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

        if (dynamic_cast<Wall*>(neighbourTile) == nullptr) {
            neighbours.push_back(neighbourTile);
        }
        /*bool neighbourTileIsEnterable = false;

        Character dummyCharacter = Character(10, 10, 10, false);

        //TODO: ACHTUNG, DAS HAT SEITENEFFEKTE!
        //TODO: Portale
        Tile* fromTile = tile->onLeave(neighbourTile, &dummyCharacter);
        Tile* enteredTile = neighbourTile->onEnter(fromTile, &dummyCharacter);

        if (fromTile != nullptr && enteredTile != nullptr) {
            neighbourTileIsEnterable = true;
            neighbours.push_back(neighbourTile);
        }*/
    }

    cout << endl << "Neighbours at: ";

    for (auto neighbour : neighbours) {
        cout << neighbour->getRow() << " " << neighbour->getColumn() << ", ";
    }

    cout << endl;

    return neighbours;
}

vector<Tile *> Graph::filterOutVisitedTiles(vector<Tile *> tiles, map<Tile*, tuple<int, Tile *, bool>> &nodes)
{
    vector<Tile*> unvisitedTiles;

    for (auto tile : tiles) {
        if (get<2>(nodes[tile]) == false) {
            unvisitedTiles.push_back(tile);
        }
    }

    cout << endl << "Unvisited Tiles at: ";

    for (auto tile : unvisitedTiles) {
        cout << tile->getRow() << " " << tile->getColumn() << "; ";
    }

    cout << endl;

    return unvisitedTiles;
}
