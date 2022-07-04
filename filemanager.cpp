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

    for (auto levelAsJson : json["levellist"]) {
        //cout << level["id"] << endl;

        //Level* level = Level()
        vector<string> layout = levelAsJson["layout"];
        vector<vector<string>> finalLayout;

        for (auto row : layout) {
            vector<string> finalRow;

            for (char tile : row) {
                string tileAsString = string(1, tile);
                finalRow.push_back(tileAsString);
            }

            finalLayout.push_back(finalRow);
        }

        Level* level = new Level(finalLayout);

        level->setId(levelAsJson["id"]);

        for (auto characterAsJson : levelAsJson["characters"]) {
            int strength = characterAsJson["strength"];
            int stamina = characterAsJson["stamina"];
            int hitpoints = characterAsJson["hitpoints"];
            bool isPlayer = characterAsJson["isPlayer"];
            int row = characterAsJson["row"];
            int col = characterAsJson["col"];
            int moveDirection = characterAsJson["moveDirection"];

            Character* character = new Character(strength, stamina, hitpoints, isPlayer);
            character->setId(characterAsJson["id"]);
            character->setMoveDirection(moveDirection);
            level->placeCharacter(character, row, col);
        }

        levellist->push_back(level);

    }

    return levellist;
}
