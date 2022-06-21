#include "dungeoncrawler.h"
#include "character.h"
#include "level.h"
#include "levelchanger.h"
#include "terminalui.h"
#include "graphicalui.h"

#include <QTest>

DungeonCrawler::DungeonCrawler()
{
    Level* level = new Level(10, 10);

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

    levels.push_back(level);
    currentLevel = level;

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
                cout << "Guck mal, ich hab nen Levelchanger gefunden" << "!!!" << endl;
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

void DungeonCrawler::notify(Active* source) {
    cout << "Fühlen Sie es jetzt mr. Krabs?";
    qDebug("HalLOOOOOOOO");
}
