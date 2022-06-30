#include "graph.h"

Graph::Graph(Level* level)
{
    this->level = level;
    //generiert adjacencyList basierend auf Tilepointer des Levels
}

vector<Tile*> Graph::getPath(Tile *from, Tile *to) {//JZ WILL ICH DAS MAL TESTEN
    vector<Tile*> path;

    map<Tile*, pair<int, Tile*>> nodes = initializeDijkstra(from);

    /*
    nachbarn = neighboursFrom(from)

    for (nachbar of nachbarn) {
        getPath(nachbar, to)
    }


    irgendwie muss mit nem bool makiert werden, welche Knoten bereits besucht wurden

    Abbruchbedingung?
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
