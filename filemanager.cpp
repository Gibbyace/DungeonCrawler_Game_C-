#include "filemanager.h"
#include <fstream>

Filemanager::Filemanager()
{

}

nlohmann::json Filemanager::loadLevels()
{
    std::ifstream file("../pg2_Di45y-TeamA-Herrmann_Kotwal/levels.json");

    nlohmann::json levels;

    file >> levels;

    return levels;
}

LevelList *Filemanager::createLevelListFromJSON(nlohmann::json json)
{
    LevelList* levellist = new LevelList();

    for (auto level : json["levellist"]) {
        cout << level["id"] << endl;
    }

    return levellist;
}
