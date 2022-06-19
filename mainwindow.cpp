#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "endscreen.h"
#include <door.h>
#include <floor.h>
#include <pit.h>
#include <portal.h>
#include <ramp.h>
#include <switch.h>
#include <wall.h>
#include <QDebug>


MainWindow::MainWindow(Level* level, TextureContainer* texturecontainer, GraphicalUI *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    changesDrawn = true;

    QWidget::setStyleSheet(("Background-color: #030306;"));

    QPixmap bloodyFrame = texturecontainer->getBackgrounds()[0];
    ui->label->setPixmap(bloodyFrame);
    ui->label->setScaledContents(true);
    ui->label->raise();
    ui->label->setStyleSheet(("Background-color: transparent;"));


    ui->gridLayoutWidget_2->raise();
    ui->statusbar->setStyleSheet(("background-color: #F00"));

    setupPlayingField(texturecontainer, level);
    setupArrowButtons(texturecontainer, parent);
}

void MainWindow::setupPlayingField(TextureContainer* texturecontainer, Level* level) {
    int gridWidth = ui->gridLayoutWidget->width();
    int gridHeight = ui->gridLayoutWidget->height();
    int tileSize = min(gridWidth / level->getWidth(), gridHeight / level->getHeight());

    srand(time(NULL));

    vector<vector<int>> portalPositions;

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            QPixmap tilePixmap;
            Tile* currentTile = level->getTilepointer()[row][col];

            if (dynamic_cast<Door*>(currentTile) != nullptr) {
                tilePixmap = texturecontainer->getDoors()[0];
            }
            else if (dynamic_cast<Floor*>(currentTile) != nullptr) {
                int tileTextureCount = texturecontainer->getFloors().size();
                int randomizer = rand() % tileTextureCount;

                tilePixmap = texturecontainer->getFloors()[randomizer];
            }
            else if (dynamic_cast<Pit*>(currentTile) != nullptr) {
                tilePixmap = texturecontainer->getPits()[0];
            }
            else if (dynamic_cast<Portal*>(currentTile) != nullptr) {
                Portal* currentPortal = dynamic_cast<Portal*>(currentTile);
                Portal* connectedPortal = dynamic_cast<Portal*>(currentPortal->getDestination());

                int connectedPortalRow = connectedPortal->getRow();
                int connectedPortalCol = connectedPortal->getCol();

                portalPositions.push_back({row, col});
                portalPositions.push_back({connectedPortalRow, connectedPortalCol});
            }
            else if (dynamic_cast<Ramp*>(currentTile) != nullptr) {
                tilePixmap = texturecontainer->getRamps()[0];
            }
            else if (dynamic_cast<Switch*>(currentTile) != nullptr) {
                tilePixmap = texturecontainer->getSwitches()[0];
            }
            else if (dynamic_cast<Wall*>(currentTile) != nullptr) {
                tilePixmap = texturecontainer->getWalls()[0];
            }
            else {
                tilePixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
            }

            QLabel* newTile = new QLabel();
            newTile->setAttribute(Qt::WA_TranslucentBackground,true);
            newTile->setScaledContents(true);
            newTile->setPixmap(tilePixmap);
            newTile->setFixedSize(tileSize, tileSize);

            ui->gridLayout->addWidget(newTile, row, col);

            if (currentTile->hasCharacter()) {
                Character* characterOfCurrentTile = currentTile->getCharacter();

                QLabel* characterLabel;

                characterLabel = new QLabel();

                characterLabel->setScaledContents(true);
                characterLabel->setPixmap(texturecontainer->getCharFronts()[1]);
                characterLabel->setStyleSheet(("background-color: transparent;"));
                characterLabel->setMinimumSize(tileSize, tileSize);
                characterLabel->setMaximumSize(tileSize, tileSize);
                characterLabel->setParent(newTile);

                characterLabels[characterOfCurrentTile->getId()] = characterLabel;
            }
        }
    }

    int portalCounter = 0;

    for (unsigned i = 0; i < portalPositions.size(); i++) {
        int portalRow = portalPositions[i][0];
        int portalCol = portalPositions[i][1];

        QWidget* portalWidget = ui->gridLayout->itemAtPosition(portalRow, portalCol)->widget();
        QLabel* portalLabel = dynamic_cast<QLabel*>(portalWidget);
        portalLabel->setPixmap(texturecontainer->getPortals()[portalCounter / 2 % 3]);

        portalCounter++;
    }
}

void MainWindow::setupArrowButtons(TextureContainer* texturecontainer, GraphicalUI* parent) {
    ui->topleftbutton->setIcon(     QIcon(texturecontainer->getArrows()[3]));
    ui->topbutton->setIcon(         QIcon(texturecontainer->getArrows()[4]));
    ui->toprightbutton->setIcon(    QIcon(texturecontainer->getArrows()[5]));
    ui->rightbutton->setIcon(       QIcon(texturecontainer->getArrows()[6]));
    ui->bottomrightbutton->setIcon( QIcon(texturecontainer->getArrows()[7]));
    ui->bottombutton->setIcon(      QIcon(texturecontainer->getArrows()[0]));
    ui->bottomleftbutton->setIcon(  QIcon(texturecontainer->getArrows()[1]));
    ui->leftbutton->setIcon(        QIcon(texturecontainer->getArrows()[2]));
    ui->centerbutton->setIcon(      QIcon(texturecontainer->getArrows()[8]));

    connect(ui->topleftbutton,      &QPushButton::clicked, [parent]() {parent->setLastInput(7);});
    connect(ui->topbutton,          &QPushButton::clicked, [parent]() {parent->setLastInput(8);});
    connect(ui->toprightbutton,     &QPushButton::clicked, [parent]() {parent->setLastInput(9);});
    connect(ui->rightbutton,        &QPushButton::clicked, [parent]() {parent->setLastInput(6);});
    connect(ui->bottomrightbutton,  &QPushButton::clicked, [parent]() {parent->setLastInput(3);});
    connect(ui->bottombutton,       &QPushButton::clicked, [parent]() {parent->setLastInput(2);});
    connect(ui->bottomleftbutton,   &QPushButton::clicked, [parent]() {parent->setLastInput(1);});
    connect(ui->leftbutton,         &QPushButton::clicked, [parent]() {parent->setLastInput(4);});
    connect(ui->centerbutton,       &QPushButton::clicked, [parent]() {parent->setLastInput(5);});

    QObjectList arrowButtons = ui->buttonGridLayout->children();

    for (int i = 0; i < arrowButtons.size(); i++) {
        QPushButton* arrowButton = dynamic_cast<QPushButton*>(arrowButtons[i]);

        if (arrowButton != nullptr) {
            arrowButton->setIconSize(QSize(40, 40));
        }
    }
}

QPixmap MainWindow::setCharacterPixmapFromDirection(int characterMoveDirection, TextureContainer* texturecontainer) {
    QPixmap characterPixmap = texturecontainer->getCharBacks()[0];

    if (characterMoveDirection == 7) {
        characterPixmap = QPixmap(texturecontainer->getCharBacks()[0]);
    }
    else if (characterMoveDirection == 8) {
        characterPixmap = QPixmap(texturecontainer->getCharBacks()[1]);
    }
    else if (characterMoveDirection == 9) {
        characterPixmap = QPixmap(texturecontainer->getCharBacks()[2]);
    }
    else if (characterMoveDirection == 6) {
        characterPixmap = QPixmap(texturecontainer->getCharRights()[0]);
    }
    else if (characterMoveDirection == 3) {
        characterPixmap = QPixmap(texturecontainer->getCharFronts()[0]);
    }
    else if (characterMoveDirection == 2 || characterMoveDirection == 5) {
        characterPixmap = QPixmap(texturecontainer->getCharFronts()[1]);
    }
    else if (characterMoveDirection == 1) {
        characterPixmap = QPixmap(texturecontainer->getCharFronts()[2]);
    }
    else if (characterMoveDirection == 4) {
        characterPixmap = QPixmap(texturecontainer->getCharLefts()[0]);
    }

    return characterPixmap;
}

void MainWindow::setStatusbarMessage(Level* level) {
    QString statusbarMessage = "Strength: ";

    statusbarMessage.append(QString::number(level->getPlayerCharacter()->getStrength()));
    statusbarMessage.append("; Stamina: ");
    statusbarMessage.append(QString::number(level->getPlayerCharacter()->getStamina()));
    statusbarMessage.append("; Hitpoints: ");
    statusbarMessage.append(QString::number(level->getPlayerCharacter()->getHitpoints()));
    statusbarMessage.append("; MaxHP: ");
    statusbarMessage.append(QString::number(level->getPlayerCharacter()->getMaxHP()));

    ui->statusbar->showMessage(statusbarMessage);
}

void MainWindow::draw(Level* level, TextureContainer* texturecontainer) {
    if (changesDrawn) {
        return;
    }

    changesDrawn = true;

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getHeight(); col++) {
            Tile* currentTile = level->getTilepointer()[row][col];

            if (dynamic_cast<Door*>(currentTile) != nullptr) {
                QWidget* doorWidget = ui->gridLayout->itemAtPosition(row, col)->widget();

                if (currentTile->getTexture() == "/") {
                    dynamic_cast<QLabel*>(doorWidget)->setPixmap(texturecontainer->getDoors()[1]);
                }
                else if (currentTile->getTexture() == "X") {
                    dynamic_cast<QLabel*>(doorWidget)->setPixmap(texturecontainer->getDoors()[0]);
                }
            }

            if (dynamic_cast<Pit*>(currentTile) != nullptr) {
                QLabel* pitAsLabel = dynamic_cast<QLabel*>(ui->gridLayout->itemAtPosition(row, col)->widget());
                pitAsLabel->setPixmap(texturecontainer->getPits()[0]);
            }

            if (currentTile->hasCharacter()) {
                QWidget* parentForCharacter = ui->gridLayout->itemAtPosition(row, col)->widget();
                QLabel* parentAsLabel = dynamic_cast<QLabel*>(parentForCharacter);

                Character* characterOnTile = currentTile->getCharacter();
                vector<Character*> characters = level->getCharacterpointer();

                characterLabels[characterOnTile->getId()]->setParent(parentAsLabel);
                characterLabels[characterOnTile->getId()]->show();

                int characterMoveDirection = currentTile->getCharacter()->getMoveDirection();

                QPixmap characterPixmap = setCharacterPixmapFromDirection(characterMoveDirection, texturecontainer);

                characterLabels[characterOnTile->getId()]->setPixmap(QPixmap(characterPixmap));

                if (dynamic_cast<Pit*>(currentTile) != nullptr) {
                    QLabel* pitAsLabel = dynamic_cast<QLabel*>(ui->gridLayout->itemAtPosition(row, col)->widget());
                    pitAsLabel->setPixmap(QPixmap(characterPixmap));

                    characterLabels[characterOnTile->getId()]->setPixmap(texturecontainer->getPits()[0]);
                }
            }
        }
    }

    setStatusbarMessage(level);
}

void MainWindow::setChangesDrawn(bool value)
{
    changesDrawn = value;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent* event) {
    GraphicalUI* parentAsGUI = dynamic_cast<GraphicalUI*>(parent());

    if (parentAsGUI != nullptr) {
        parentAsGUI->setUserWantsToEndThisApp(true);
    }
}
void MainWindow::characterIsDead(Level *level){

    if(level->getPlayerCharacter()->getHitpoints()==0)
    {
        endscreen endscreen1;
        endscreen1.show();
    }
}

