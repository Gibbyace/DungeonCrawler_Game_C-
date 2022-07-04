#include "graph.h"
#include "door.h"
#include "wall.h"
#include "pit.h"
#include "ramp.h"
#include "portal.h"
#include <iomanip>

Graph::Graph(Level* level)
{
    this->level = level;
}

list<Tile*> Graph::getPath(Tile *from, Tile *to) {
    map<Tile*, tuple<int, Tile*, bool>> nodes = initializeDijkstra(from);

    nodes = executeDijkstra(from, nodes);

    list<Tile*> path = calculatePath(from, to, nodes);

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

map<Tile*, tuple<int, Tile*, bool>> Graph::executeDijkstra(Tile* from, map<Tile*, tuple<int, Tile*, bool>> &nodes) {
    //cout << endl << "Looking at: " << from->getRow() << " " << from->getColumn() << endl << endl;

    //speichern, dass from besucht wurde
    nodes[from] = {get<0>(nodes[from]), get<1>(nodes[from]), true};

    //printNodes(nodes);

    vector<Tile*> neighbours = neighboursFrom(from);

    if (neighbours.size() == 0) {
        return nodes;
    }

    nodes = updateDistancesToNeighbours(from, neighbours, nodes);

    vector<Tile*> unvisitedNeighbours = filterOutVisitedTiles(neighbours, nodes);

    //Das ganze mit den unbesuchten Nachbarn ausführen und zwar immer den mit der niedrigsten Distanz zuerst
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

map<Tile *, tuple<int, Tile *, bool> > Graph::updateDistancesToNeighbours(
        Tile *from,
        const vector<Tile*> &neighbours,
        map<Tile *, tuple<int, Tile *, bool>> &nodes
)
{
    for (auto neighbour : neighbours) {
        int shortestDistanceToThisNeighbourYet = get<0>(nodes[neighbour]);

        if (
                get<0>(nodes[from]) < shortestDistanceToThisNeighbourYet ||
                shortestDistanceToThisNeighbourYet == -1
        ) {
            get<0>(nodes[neighbour]) = get<0>(nodes[from]) + 1;
            get<1>(nodes[neighbour]) = from;
        }
    }

    return nodes;
}

void Graph::printNodes(map<Tile *, tuple<int, Tile *, bool>>& nodes) {
    for (unsigned row = 0; row < level->getTilepointer().size(); row++) {
        for (unsigned col = 0; col < level->getTilepointer()[row].size(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];
            std::cout.width(5);

            //cout << get<0>(nodes[currentTile]);
        }

        //cout << endl;
    }

    //cout << endl;
}

vector<Tile *> Graph::neighboursFrom(Tile *from)
{
    vector<Tile*> neighbours;
    vector<vector<Tile*>> tiles = level->getTilepointer();
    int row = from->getRow();
    int col = from->getColumn();

    vector<pair<int, int>> relativeNeighbourPositions = {
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
    };

    bool fromIsPortal = dynamic_cast<Portal*>(from) != nullptr;

    if (fromIsPortal) {
        Tile* connectedPortal = dynamic_cast<Portal*>(from)->getDestination();
        neighbours.push_back(connectedPortal);
    }

    for (unsigned i = 0; i < relativeNeighbourPositions.size(); i++) {
        int neighbourRow = row + relativeNeighbourPositions[i].first;
        int neighbourCol = col + relativeNeighbourPositions[i].second;

        if (neighbourCol < 0 || neighbourRow < 0) {
            continue;
        }

        Tile* neighbour = tiles[neighbourRow][neighbourCol];

        bool neighbourIsWall = dynamic_cast<Wall*>(neighbour) != nullptr;
        bool tileIsPit = dynamic_cast<Pit*>(from) != nullptr;
        bool neighbourIsNotPitAndNotRamp =
                dynamic_cast<Pit*>(neighbour) == nullptr &&
                dynamic_cast<Ramp*>(neighbour) == nullptr;
        bool neighbourIsDoor = dynamic_cast<Door*>(neighbour);

        if (neighbourIsWall) {
            continue;
        }
        else if (neighbourIsDoor) {
            Door* neighbourAsDoor = dynamic_cast<Door*>(neighbour);
            if (neighbourAsDoor->getTexture() == "X") {
                continue;
            }
        }
        else if (tileIsPit && neighbourIsNotPitAndNotRamp) {
            continue;
        }

        neighbours.push_back(neighbour);
    }

    //cout << endl << "Neighbours at: ";

    for (auto neighbour : neighbours) {
        //cout << neighbour->getRow() << " " << neighbour->getColumn() << ", ";
    }

    //cout << endl;

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

    //cout << endl << "Unvisited Tiles at: ";

    for (auto tile : unvisitedTiles) {
        //cout << tile->getRow() << " " << tile->getColumn() << "; ";
    }

    //cout << endl;

    return unvisitedTiles;
}

list<Tile*> Graph::calculatePath(Tile *from, Tile *to, map<Tile *, tuple<int, Tile *, bool> > &nodes) {
    list<Tile*> path;

    if (get<0>(nodes[to]) == -1) {
        return path;
    }

    while (to != from) {
        path.push_front(to);
        Tile* previousTile = get<1>(nodes[to]);
        to = previousTile;
    }

    //cout << endl << "Path: ";

    for (Tile* tile : path) {
        //cout << tile->getRow() << " " << tile->getColumn() << ", ";
    }

    //cout << endl;

    return path;
}
