#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "json.hpp"
#include "levellist.h"

class Filemanager
{
public:
    Filemanager();
    nlohmann::json loadLevels();
    LevelList* createLevelListFromJSON(nlohmann::json json);
    nlohmann::json createJSONFromLevelList(LevelList* levellist);
    void saveLevels(nlohmann::json json);
    void resetGameData();
};

#endif // FILEMANAGER_H
