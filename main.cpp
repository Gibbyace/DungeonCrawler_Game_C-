#include <iostream>
#include "dungeoncrawler.h"
#include <QApplication>

#include "filemanager.h"

using namespace std;

int main(int argc, char* argv[])
{
    //Filemanager filemanager = Filemanager();
    //nlohmann::json json = filemanager.loadLevels();
    //LevelList* levellist = filemanager.createLevelListFromJSON(json);

    QApplication application(argc, argv);

    DungeonCrawler Game1 = DungeonCrawler();
    Game1.play();

    return 0;
}
