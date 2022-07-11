#include "filemanager.h"
#include "attackcontroller.h"
#include "json.hpp"
#include "door.h"
#include "portal.h"
#include <fstream>

Filemanager::Filemanager()
{

}

void Filemanager::saveLevels(nlohmann::json levellistAsJson) {
    std::ofstream saveFile("../pg2_Di45y-TeamA-Herrmann_Kotwal/levels.json");
    saveFile << levellistAsJson;
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

            vector<Levelchanger*> levelchangers = level->getLevelchangers();

            levelchangers.push_back(levelchanger);
            level->setLevelchangers(levelchangers);
        }

        for (auto portalpair : levelAsJson["portalpairs"]) {
            int portalsrow1  = portalpair["row1"];
            int portalscol1  = portalpair["col1"];
            int portalsrow2  = portalpair["row2"];
            int portalscol2  = portalpair["col2"];

            level->placePortals(portalsrow1,portalscol1,portalsrow2,portalscol2);
        }

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



// save file
nlohmann::json Filemanager::createJSONFromLevelList(LevelList *levellist)
{
    nlohmann::json levelsAsJson;
    levelsAsJson["levellist"] = {};

    for (LevelList::iterator it = levellist->begin(); it.m_ptr != levellist->end().m_ptr; it++) {
        nlohmann::json levelAsJson;

        Level* level = it.m_ptr->level;

        int levelID = level->getId();
        levelAsJson["id"] = levelID;
        //konverter level to string

        levelAsJson["characters"] = {};

        for (unsigned int i = 0; i<level->getCharacterpointer().size(); i++) {
            nlohmann::json character;

            int id = level->getCharacterpointer()[i]->getId();
            int row = level->getCharacterpointer()[i]->getTile()->getRow();
            int col = level->getCharacterpointer()[i]->getTile()->getColumn();
            int strength = level->getCharacterpointer()[i]->getStrength();
            int stamina = level->getCharacterpointer()[i]->getStamina();
            int hitpoints = level->getCharacterpointer()[i]->getHitpoints();
            bool isplayer = level->getCharacterpointer()[i]->getIsPlayerCharacter();
            int movedirection = level->getCharacterpointer()[i]->getMoveDirection();

            //insert to json
            character["id"] = id;
            character["row"] = row;
            character["col"] = col;
            character["strength"] = strength;
            character["stamina"] = stamina;
            character["hitpoints"] = hitpoints;
            character["moveDirection"] = movedirection;
            character["isPlayer"] = isplayer;

            levelAsJson["characters"].push_back(character);
        }


        levelAsJson["levelchangers"] = {};

        for (unsigned int i = 0; i < level->getLevelchangers().size();i++) {
            nlohmann::json levelchanger;
            int row = level->getLevelchangers()[i]->getRow();
            int col = level->getLevelchangers()[i]->getColumn();
            int destinationLevelID = level->getLevelchangers()[i]->getDestinationLevelId();

            //insert to json
            levelchanger["row"] = row;
            levelchanger["col"] = col;
            levelchanger["destinationLevelID"] = destinationLevelID;

            levelAsJson["levelchangers"].push_back(levelchanger);
        }

        nlohmann::json switches = {};
        nlohmann::json portals = {};


        vector<string> layoutString;

        for (unsigned int row = 0; row < level->getTilepointer().size(); row++) {
            string rowOfTiles;

            for (unsigned col = 0; col < level->getTilepointer()[row].size(); col++) {
                Tile* tile = level->getTilepointer()[row][col];
                string texture = tile->getTexture();

                if (
                        texture == "#" or
                        texture == "." or
                        texture == "_" or
                        texture == "<" or
                        texture == "e"
                        ) {
                    rowOfTiles += texture;
                }
                else {
                    rowOfTiles += ".";
                }

                if ("O" == texture) {
                    nlohmann::json portal;

                    Portal* tileAsPortal = dynamic_cast<Portal*>(tile);
                    Tile* connectedPortal = tileAsPortal->getDestination();

                    portal["row1"] = tile->getRow();
                    portal["col1"] = tile->getColumn();
                    portal["row2"] = connectedPortal->getRow();
                    portal["col2"] = connectedPortal->getColumn();

                    portals.push_back(portal);
                }


                else if ("?" == texture) {
                    nlohmann::json switchAsJson;

                    switchAsJson["row"] = row;
                    switchAsJson["col"] = col;

                    Active* switchAsActive = dynamic_cast<Active*>(tile);
                    vector<Passive*> connectedDoorsAsPassive = switchAsActive->getObservers();

                    for (Passive* doorAsPassive : connectedDoorsAsPassive) {
                        Door* door = dynamic_cast<Door*>(doorAsPassive);
                        nlohmann::json connectedDoorAsJson;

                        connectedDoorAsJson["row"] = door->getRow();
                        connectedDoorAsJson["col"] = door->getColumn();

                        if (door->getTexture() == "X") {
                            connectedDoorAsJson["isOpen"] = false;
                        }
                        else {
                            connectedDoorAsJson["isOpen"] = true;
                        }

                        switchAsJson["connectedDoor"] = connectedDoorAsJson;
                    }

                    switches.push_back(switchAsJson);
                }
            }
            layoutString.push_back(rowOfTiles);
        }

        levelAsJson["switches"] = switches;
        levelAsJson["portalpairs"] = portals;
        levelAsJson["layout"]  = layoutString;
        levelsAsJson["levellist"].push_back(levelAsJson);
    }

    return levelsAsJson;
}

void Filemanager::resetGameData() {
    std::ifstream originalFile("../pg2_Di45y-TeamA-Herrmann_Kotwal/levels-original.json");
    std::ofstream saveFile("../pg2_Di45y-TeamA-Herrmann_Kotwal/levels.json");
    nlohmann::json levels;

    originalFile >> levels;
    saveFile << levels;
}
