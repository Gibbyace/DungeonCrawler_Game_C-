#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include "level.h"
#include "tile.h"

using namespace std;

class Graph
{
private:
    map<Tile*, vector<Tile*>> adjacencyList;
    map<Tile*, tuple<int, Tile*, bool>> initializeDijkstra(Tile* from);
    vector<Tile*> neighboursFrom(Tile* tile);
    Level* level;

public:
    Graph(Level* level);
    vector<Tile*> getPath(Tile* from, Tile* to, int traveledDistance = 0);
};

#endif // GRAPH_H
