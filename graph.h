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
    map<Tile*, tuple<int, Tile*, bool>> executeDijkstra(Tile* from, map<Tile*, tuple<int, Tile*, bool>> nodes);
    void printNodes(map<Tile*, tuple<int, Tile*, bool>> &nodes);
    vector<Tile*> neighboursFrom(Tile* tile);
    vector<Tile*> filterOutVisitedTiles(vector<Tile*> tiles, map<Tile*, tuple<int, Tile*, bool>> &nodes);
    Level* level;

public:
    Graph(Level* level);
    vector<Tile*> getPath(Tile* from, Tile* to);
};

#endif // GRAPH_H
