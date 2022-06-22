#include "dungeoncrawler.h"
#include "character.h"
#include "level.h"
#include "levelchanger.h"
#include "terminalui.h"
#include "graphicalui.h"

#include <QTest>

void DungeonCrawler::connectLevels() {
    for (LevelList::iterator it = levels.begin(); it != levels.end(); it++) {
        Level* level = it.m_ptr->level;
        Level* nextLevel = it.m_ptr->next->level;

        //levelchanger des Levels suchen und destinationLevel des levelchangers auf das nächste Level
        for (int row = 0; row < level->getHeight(); row++) {
            for (int col = 0; col < level->getWidth(); col++) {
                Tile* currentTile = level->getTilepointer()[row][col];
                Levelchanger* currentTileAsLevelchanger = dynamic_cast<Levelchanger*>(currentTile);

                if (currentTileAsLevelchanger != nullptr) {
                    currentTileAsLevelchanger->setDestinationLevel(nextLevel);
                }
            }
        }
    }
}

void DungeonCrawler::generateLevels() {
    Level* level1 = new Level(
        {
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", "_", "_", ".", ".", ".", ".", ".", ".", "#"},
        {"#", ".", "_", ".", ".", ".", ".", ".", "N", "#"},
        {"#", ".", "_", ".", ".", ".", ".", "e", ".", "#"},
        {"#", ".", "_", ".", ".", "X", ".", ".", ".", "#"},
        {"#", ".", "<", ".", ".", ".", ".", ".", ".", "#"},
        {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
        {"#", ".", ".", ".", ".", "l", ".", ".", ".", "#"},
        {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
        }, 10, 10
    );

    Level* level2 = new Level({
      {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
      {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
      {"#", ".", "l", ".", ".", ".", ".", ".", ".", "#"},
      {"#", "_", "_", "_", ".", ".", ".", ".", "N", "#"},
      {"#", ".", ".", "_", ".", ".", ".", "e", ".", "#"},
      {"#", "_", "_", "_", ".", "X", ".", ".", ".", "#"},
      {"#", "_", ".", ".", ".", ".", ".", ".", ".", "#"},
      {"#", "_", "_", "<", ".", ".", ".", ".", ".", "#"},
      {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
      {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
      }, 10, 10);

    levels.push_back(level1);
    levels.push_back(level2);

    currentLevel = level1;

    connectLevels();
}

DungeonCrawler::DungeonCrawler()
{
    generateLevels();

    //Level* level = new Level(10, 10);

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

    //levels.push_back(level);

    //currentLevel = level;

    this->abstractUI = new GraphicalUI(levels.begin().m_ptr->level);
    //this->abstractUI = new TerminalUI();
}

DungeonCrawler::~DungeonCrawler() {
    delete this->abstractUI;

    while (!levels.empty()) {
        //delete levels.back();
        levels.pop_back();
    }
}

void DungeonCrawler::play()
{
    abstractUI->printDirectionOptions();

    setLevel(levels.begin().m_ptr->level);
    //vielleicht wollen wir hier lieber nen Iterator benutzen

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
                tileWithCharacter->moveTo(destinationTile, character);
            }
        }

        abstractUI->draw(currentLevel);

        //Muss für TerminalUI auskommentiert werden
        abstractUI->setInputProcessed(true);
    }
}

void DungeonCrawler::setLevel(Level *level) {
    currentLevel = level;

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];

            if (dynamic_cast<Levelchanger*>(currentTile) != nullptr) {
                dynamic_cast<Active*>(currentTile)->attach(this);
            }
        }
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
