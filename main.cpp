#include <iostream>
#include "dungeoncrawler.h"

#include <wall.h>
#include <floor.h>

using namespace std;

int main()
{
    Wall* testWall = new Wall(0, 0);
    cout << testWall->getTexture() << endl << endl;

    Floor* testFloor = new Floor(0, 0);
    cout << testFloor->getTexture() << endl << endl;


    DungeonCrawler Game1;
    Game1.play();

    //TODO: Warum werden Walls nicht dargestellt?
}
