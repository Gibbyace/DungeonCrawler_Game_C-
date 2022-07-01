#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>

#include "levellist.h"

#include "graph.h"

using namespace std;

int main(int argc, char* argv[])
{
    Level* desdLevel = new Level({
         {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
         {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
         {"#", ".", "l", ".", ".", ".", ".", ".", ".", "#"},
         {"#", "_", "_", "_", ".", ".", ".", ".", "N", "#"},
         {"#", ".", ".", "_", ".", ".", ".", "e", ".", "#"},
         {"#", "_", "_", "_", ".", "X", ".", ".", ".", "#"},
         {"#", "_", ".", ".", ".", ".", ".", ".", ".", "#"},
         {"#", "_", "_", "<", ".", ".", ".", ".", ".", "#"},
         {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
         {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
    });

    Graph desdGraph = Graph(desdLevel);
    Tile* from = desdLevel->getTilepointer()[8][8];
    Tile* to = desdLevel->getTilepointer()[2][2];
    desdGraph.getPath(from, to);

    /*QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    Game1.play();*/

    return 0;
}
