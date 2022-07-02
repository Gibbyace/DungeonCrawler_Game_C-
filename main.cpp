#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>

#include "levellist.h"

#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Level* desdLevel = new Level({
     {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
     {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", "#"},
     {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", "#"},
     {"#", ".", ".", ".", ".", ".", ".", "N", ".", "#", "#"},
     {"#", "#", "#", "#", "#", "#", "#", "#", ".", "#", "#"},
     {"#", ".", ".", ".", ".", "X", ".", ".", ".", "#", "#"},
     {"#", ".", "<", ".", ".", ".", ".", ".", ".", "#", "#"},
     {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#", "#"},
     {"#", ".", ".", ".", ".", "l", ".", ".", ".", "#", "#"},
     {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
     {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
     });

    Graph desdGraph = Graph(desdLevel);
    Tile* from = desdLevel->getTilepointer()[1][1];
    Tile* to = desdLevel->getTilepointer()[2][2];
    desdGraph.getPath(from, to);

    /*QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    Game1.play();*/

    return 0;
}
