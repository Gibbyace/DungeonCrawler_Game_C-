#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>
#include "startscreen.h"
#include <QMainWindow>

using namespace std;

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    /*Game1.play();*/

    QMainWindow w;
    w.show();

    return application.exec();

    cout << "Goodbye! This was a lot of fun!- PLS come back" << endl << "I miss you <3" << endl << endl;
}
