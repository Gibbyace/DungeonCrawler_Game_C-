#include <iostream>
#include "dungeoncrawler.h"

using namespace std;

int main()
{
    DungeonCrawler *Game1 = new DungeonCrawler();
    Game1->play();

    delete Game1;

    cout << "Goodbye! This was a lot of fun!- PLS come back" << endl << "I miss you <3" << endl << endl;
}
