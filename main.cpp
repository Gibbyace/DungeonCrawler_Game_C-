#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>

#include "levellist.h"

#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Level* testLevel = new Level({
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", "N", ".", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "_", "#", "#"},
        {"#", ".", "X.", ".", ".", ".", ".", "_", "_", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", "_", "_", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", "_", "_", "#", "#"},
        {"#", ".", ".", ".", ".", "l", ".", "<", ".", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
    });

    //TODO: ACHTUNG placePortals gehört zu protected!!!
    testLevel->placePortals(2, 2, 3, 8);

    Graph testGraph = Graph(testLevel);
    Tile* from = testLevel->getTilepointer()[1][1];
    Tile* to = testLevel->getTilepointer()[2][2];
    testGraph.getPath(from, to);

    /*QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    Game1.play();*/

    return 0;
}
