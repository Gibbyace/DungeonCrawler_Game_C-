﻿#include "filemanager.h"
#include "attackcontroller.h"
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

            if (!isPlayer) {
                character->setController(new Attackcontroller(level, character));
            }

            level->placeCharacter(character, row, col);
            level->characterpointerpushback(character);
        }

        levellist->push_back(level);

        for (auto levelchangersAsJson : levelAsJson["levelchangers"]) {
            int row = levelchangersAsJson["row"];
            int col= levelchangersAsJson["col"];
            int destinationID   = levelchangersAsJson["destinationLevelID"];

            Levelchanger* levelchanger = new Levelchanger(row, col);

            levelchanger->setDestinationLevelId(destinationID);

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

        auto test = levelAsJson["switches"][0]["row"];

        for (unsigned i = 0; i<levelAsJson["switches"].size(); i++) {
            int switchRow = levelAsJson["switches"][i]["row"];
            int switchCol = levelAsJson["switches"][i]["col"];
            int doorRow = levelAsJson["switches"][i]["connectedDoor"]["row"];
            int doorCol = levelAsJson["switches"][i]["connectedDoor"]["col"];
            level->placeSwitchAndDoor(switchRow, switchCol, doorRow, doorCol);
        }
    }

    for (LevelList::iterator it = levellist->begin(); it.m_ptr != levellist->end().m_ptr; it++) {
        Level* level = it.m_ptr->level;

        for (Levelchanger* levelchanger : level->getLevelchangers()) {
            int destinationLevelId = levelchanger->getDestinationLevelId();

            for (LevelList::iterator innerit = levellist->begin(); innerit.m_ptr != levellist->end().m_ptr; innerit++) {
                Level* potentialDestinationLevel = innerit.m_ptr->level;

                if (potentialDestinationLevel->getId() == destinationLevelId) {
                    levelchanger->setDestinationLevel(potentialDestinationLevel);
                }
            }
        }
    }

    return levellist;
}
