#include "dungeoncrawler.h"
#include "character.h"
#include "level.h"
#include "levelchanger.h"
#include "lootchest.h"
#include "terminalui.h"
#include "graphicalui.h"
#include "mainwindow.h"
#include "endscreen.h"

#include <QTest>

DungeonCrawler::DungeonCrawler()
{
    filemanager = new Filemanager();
    nlohmann::json levelsAsJson = filemanager->loadLevels();
    levels = filemanager->createLevelListFromJSON(levelsAsJson);


    //levels = Level::generateLevels();
    currentLevel = levels->begin().m_ptr->level;

    //Kopierkonstruktor testen
    /*
    Level* tmp = new Level(10, 10);
    Level* level = new Level(*tmp);
    delete tmp;

    //Zuweisungsoperator testen
    tmp = new Level(10, 10);
    *level = *tmp;
    delete tmp;
    */

    this->abstractUI = new GraphicalUI(levels->begin().m_ptr->level);
    //this->abstractUI = new TerminalUI();
}

DungeonCrawler::~DungeonCrawler() {
    delete this->abstractUI;

    while (!levels->empty()) {
        levels->pop_back();
    }
}

void DungeonCrawler::play()
{
    abstractUI->printDirectionOptions();

    switchLevels(levels->begin().m_ptr->level);

    Character* playerCharacter = currentLevel->getPlayerCharacter();
    playerCharacter->setController(dynamic_cast<Controller*>(abstractUI));

    while (abstractUI->getUserWantsToEndThisApp() == false) {
        if (abstractUI->getInputProcessed() == true) {
            QTest::qWait(50);
            QCoreApplication::processEvents();
            continue;
        }

        for (unsigned i = 0; i < currentLevel->getCharacterpointer().size(); i++) {
            Character* character = currentLevel->getCharacterpointer()[i];

            int direction = character->move();

            if (direction == 0) {
                abstractUI->setUserWantsToEndThisApp(true);
            }

            Tile* tileWithCharacter = character->getTile();
            Tile* destinationTile = determineDestinationTile(currentLevel, tileWithCharacter, direction);

            if (destinationTile != nullptr) {
                bool moveSuccessful = tileWithCharacter->moveTo(destinationTile, character);
                bool battleCondition = destinationTile->hasCharacter() && character->getTile() != destinationTile;

                if (moveSuccessful && battleCondition) {
                    Character* defender = destinationTile->getCharacter();

                    if (character->getIsPlayerCharacter() != defender->getIsPlayerCharacter()) {
                        battle(character, defender);
                        checkForDeaths();
                    }
                }
            }
        }

        abstractUI->draw(currentLevel);

        checkForLootChest();

        //Muss für TerminalUI auskommentiert werden
        abstractUI->setInputProcessed(true);
    }
}

void DungeonCrawler::battle(Character* attacker, Character* defender) {
    cout << endl << attacker->getId() << " greift " << defender->getId() << " an." << endl;
    cout << "Angreifer HP: " << attacker->getHitpoints() << attacker->getIsPlayerCharacter() << endl;
    cout << "Verteidig HP: " << defender->getHitpoints() << defender->getIsPlayerCharacter() << endl;

    int attackerDamage = attacker->getStrength();
    defender->setHitpoints(defender->getHitpoints() - attackerDamage);

    if (defender->getHitpoints() > 0) {
        int defenderDamage = defender->getStrength();
        attacker->setHitpoints(attacker->getHitpoints() - defenderDamage);
    }

    cout << "Angreifer HP nachher: " << attacker->getHitpoints() << attacker->getIsPlayerCharacter() << endl;
    cout << "Verteidig HP nachher: " << defender->getHitpoints() << defender->getIsPlayerCharacter() << endl;
}

void DungeonCrawler::checkForDeaths() {
    GraphicalUI* graphicalUI = dynamic_cast<GraphicalUI*>(abstractUI);

    for (unsigned i = 0; i < currentLevel->getCharacterpointer().size(); i++) {
        Character* character = currentLevel->getCharacterpointer()[i];

        if (character->getHitpoints() <= 0) {
            if (character->getIsPlayerCharacter()) {
                graphicalUI->getMainwindow()->showEndscreen("Oh no, you ded");
            }
            else {
                int characterId = character->getId();

                currentLevel->deleteCharacterById(characterId);
                graphicalUI->getMainwindow()->deleteCharacterLabelById(characterId);
            }
        }
    }
}

void DungeonCrawler::checkForLootChest() {
    Character* playerCharacter = currentLevel->getPlayerCharacter();

    if (dynamic_cast<LootChest*>(playerCharacter->getTile()) != nullptr) {
        GraphicalUI* graphicalUI = dynamic_cast<GraphicalUI*>(abstractUI);
        graphicalUI->getMainwindow()->showEndscreen("Congratulations, you won :)");
    }
}

Tile* DungeonCrawler::determineDestinationTile(Level* level, Tile *tileWithCharacter, int direction)
{
    int rowWithCharacter = tileWithCharacter->getRow();
    int colWithCharacter = tileWithCharacter->getColumn();
    int rowDestination = rowWithCharacter;
    int colDestination = colWithCharacter;

    if (direction == 9 || direction == 7 || direction == 8) {
        if (rowWithCharacter -1 >= 0) {
            rowDestination -= 1;
        }
        else {
            return nullptr;
        }
    }

    else if (direction == 1 || direction == 2 || direction == 3) {
        if (rowWithCharacter + 1 < level->getHeight()) {
            rowDestination += 1;
        }
        else {
            return nullptr;
        }
    }

    if (direction == 7 || direction == 4 || direction == 1) {
        if (colWithCharacter - 1 >= 0) {
            colDestination -= 1;
        }
        else {
            return nullptr;
        }
    }

    else if (direction == 9 || direction == 6 || direction == 3) {
        if (colWithCharacter + 1 < level->getWidth()) {
            colDestination += 1;
        }
        else {
            return nullptr;
        }
    }

    Tile* destinationTile = level->getTilepointer()[rowDestination][colDestination];

    return destinationTile;
}

void DungeonCrawler::switchLevels(Level *level) {
    currentLevel = level;

    for (unsigned i = 0; i < level->getLevelchangers().size(); i++) {
        dynamic_cast<Active*>(level->getLevelchangers()[0])->attach(this);
    }

    //wird nicht mit Terminal funktionieren
    GraphicalUI* graphicalUI = dynamic_cast<GraphicalUI*>(abstractUI);
    graphicalUI->getMainwindow()->setupPlayingField(graphicalUI->getTexturecontainer(), level);
    graphicalUI->getMainwindow()->draw(level, graphicalUI->getTexturecontainer());

    //playerCharacter suchen und Controller auf GraphicalUI setzen
    for (unsigned i = 0; i < level->getCharacterpointer().size(); i++) {
        if (level->getCharacterpointer()[i]->getIsPlayerCharacter()) {
            level->getCharacterpointer()[i]->setController(graphicalUI);
        }
    }
}

void DungeonCrawler::notify(Active* source) {
    Level* newLevel = static_cast<Levelchanger*>(source)->getDestinationLevel();

    switchLevels(newLevel);
}
