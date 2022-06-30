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
    map<Tile*, pair<int, Tile*>> initializeDijkstra(Tile* from);
    Level* level;

public:
    Graph(Level* level);
    vector<Tile*> getPath(Tile* from, Tile* to);
};

#endif // GRAPH_H
