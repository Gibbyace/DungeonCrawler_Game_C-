#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>

#include "levellist.h"

using namespace std;

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    Game1.play();

    return 0;
}
