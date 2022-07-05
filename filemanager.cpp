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
            level->characterpointerpushback(character);
        }

        levellist->push_back(level);

        for (auto levelchangersAsJson : levelAsJson["levelchanger"]) {
            int row = levelchangersAsJson["row"];
            int col= levelchangersAsJson["clo"];
            int destinationID   = levelchangersAsJson["destinationLevelID"];

            Levelchanger* levelchanger = new Levelchanger(row, col);

            vector<vector<Tile*>> tilepointer = level->getTilepointer();
            tilepointer[row][col] = levelchanger;
            level->setTilepointer(tilepointer);

            //TODO: destination setzen

            vector<Levelchanger*> levelchangers = level->getLevelchangers();
            levelchangers.push_back(levelchanger);
            level->setLevelchangers(levelchangers);
        }

        for (auto portalpairsAsJson : levelAsJson["portalpairs"]) {
            for (auto portalpair : portalpairsAsJson) {

                int portalsrow1  = portalpair["row1"];
                int portalscol1  = portalpair["col1"];
                int portalsrow2  = portalpair["row2"];
                int portalscol2  = portalpair["col2"];

                level->placePortals(portalsrow1,portalscol1,portalsrow2,portalscol2);
            }
        }

        for (auto switchesAsJson : levelAsJson["switches"]) {
            for (auto switchAsJson : switchesAsJson) {
                int switchRow = switchesAsJson["row"];
                int switchCol = switchesAsJson["col"];
                int doorRow = switchAsJson["connectedDoor"]["row"];
                int doorCol = switchAsJson["connectedDoor"]["col"];
                level->placeSwitchAndDoor(switchRow, switchCol, doorRow, doorCol);
            }
        }
    }

    return levellist;
}
