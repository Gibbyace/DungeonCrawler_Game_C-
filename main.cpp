#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>
#include "startscreen.h"

using namespace std;

int main(int argc, char* argv[])
{
    /*
    QApplication application(argc, argv);
    DungeonCrawler *Game1 = new DungeonCrawler();
    //Game1->play();
    StartScreen w;
    w.show();
    delete Game1; //Fixed, liegt am Graphical UI bei abbruch
    return QApplication::exec();
    delete Game1; //brauchten das spiel eigentlich nicht im heap
    */

    DungeonCrawler game = DungeonCrawler();
    game.play();

    cout << "Goodbye! This was a lot of fun!- PLS come back" << endl << "I miss you <3" << endl << endl;
}
