#include "filemanager.h"
#include "attackcontroller.h"
#include "json.hpp"
#include <fstream>

Filemanager::Filemanager()
{

}

void Filemanager::saveLevels(nlohmann::json json) {


    nlohmann::json savefile;
}




nlohmann::json Filemanager::loadLevels()
{
    std::ifstream file("../pg2_Di45y-TeamA-Herrmann_Kotwal/levels.json");

    nlohmann::json levels;

    file >> levels;

    return levels;
}

//load file
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

        for (auto portalpair : levelAsJson["portalpairs"]) {
                int portalsrow1  = portalpair["row1"];
                int portalscol1  = portalpair["col1"];
                int portalsrow2  = portalpair["row2"];
                int portalscol2  = portalpair["col2"];

                level->placePortals(portalsrow1,portalscol1,portalsrow2,portalscol2);
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



// save file
nlohmann::json Filemanager::createJSONFromLevelList(LevelList *levellist)
{
    for (LevelList::iterator it = levellist->begin(); it.m_ptr != levellist->end().m_ptr; it++) {
        Level* level = it.m_ptr->level;

        int levelID = level->getId();
        //konverter level to string

        for (unsigned int i = 0; i<level->getCharacterpointer().size(); i++) {
            int id = level->getCharacterpointer()[i]->getId();
            int row = level->getCharacterpointer()[i]->getTile()->getRow();
            int col = level->getCharacterpointer()[i]->getTile()->getColumn();
            int strength = level->getCharacterpointer()[i]->getStrength();
            int stamina = level->getCharacterpointer()[i]->getStamina();
            int hitpoints = level->getCharacterpointer()[i]->getHitpoints();
            bool isplayer = level->getCharacterpointer()[i]->getIsPlayerCharacter();
            int movedirection = level->getCharacterpointer()[i]->getMoveDirection();

            //insert to json
        }
            //Texturen weitergeben?
        for (unsigned int i = 0; i<level->getLevelchangers().size();i++) {

            int row = level->getLevelchangers()[i]->getRow();
            int col = level->getLevelchangers()[i]->getColumn();
            int destinationLevelID = level->getLevelchangers()[i]->getDestinationLevelId();

            //insert to json

        }
        for (unsigned int i = 0; i<level->getTilepointer().size(); i++) {

            for (unsigned j = 0; j<level->getTilepointer().size(); i++) {
                level->getTilepointer()[i][j]->getTexture();
                //save to json

                if ("O" == level->getTilepointer()[i][j]->getTexture()) {
                    int row = i;
                    int col = j;
                    //save to json

                }

                if ("l" == level->getTilepointer()[i][j]->getTexture()) {
                    int row = i;
                    int col = j;
                    //save to json
                }

                if ("?" == level->getTilepointer()[i][j]->getTexture()) {

                    int row = level->getTilepointer()[i][j]->getRow();
                    int col = level->getTilepointer()[i][j]->getColumn();
                    //save to json

            }
                if ("X" == level->getTilepointer()[i][j]->getTexture()) {
                    int row = level->getTilepointer()[i][j]->getRow();
                    int col = level->getTilepointer()[i][j]->getColumn();
                    bool isOpen = false;
                    //save to json
                }
                else if ("/" == level->getTilepointer()[i][j]->getTexture()) {
                    int row = level->getTilepointer()[i][j]->getRow();
                    int col = level->getTilepointer()[i][j]->getColumn();
                    bool isOpen = true;
                    //save to json

                }


             }
      }

       //itterieren durch alle tilepointer der level und von dort aus platz der portale, der lootchest und co mitnehmen


    }
}
