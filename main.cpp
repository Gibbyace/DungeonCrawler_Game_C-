﻿#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>
#include "startscreen.h"
#include <QMainWindow>

using namespace std;

int main(int argc, char* argv[])
{
    cout << "Hallo, ich bin die main";
    QApplication application(argc, argv);

    StartScreen s;
    s.show();

    cout << "Hallo, hier wieder die main";
    DungeonCrawler Game1 = DungeonCrawler();
    /*Game1.play();*/

    return application.exec();

    cout << "Goodbye! This was a lot of fun!- PLS come back" << endl << "I miss you <3" << endl << endl;
}
