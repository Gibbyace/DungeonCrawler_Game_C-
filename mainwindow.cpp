#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <door.h>
#include <floor.h>
#include <pit.h>
#include <portal.h>
#include <ramp.h>
#include <switch.h>
#include <wall.h>
#include <graphicalui.h>

MainWindow::MainWindow(Level* level, TextureContainer* texturecontainer, GraphicalUI *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget::setStyleSheet(("Background-color: black;"));

    QPixmap bloodyFrame = texturecontainer->getBackgrounds()[0];
    ui->label->setPixmap(bloodyFrame);
    ui->label->setScaledContents(true);
    ui->label->raise();
    ui->label->setStyleSheet(("Background-color: transparent;"));

    ui->characterLabel->setScaledContents(true);
    ui->characterLabel->setPixmap(texturecontainer->getCharFronts()[1]);
    ui->characterLabel->setStyleSheet(("background-color: transparent;"));
    ui->characterLabel->setMinimumSize(30, 30);
    ui->characterLabel->setMaximumSize(30, 30);

    ui->gridLayoutWidget_2->raise();

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            QPixmap tilePixmap;

            if (dynamic_cast<Door*>(level->getTilepointer()[row][col]) != nullptr) {
                tilePixmap = texturecontainer->getDoors()[0];
            }
            else if (dynamic_cast<Floor*>(level->getTilepointer()[row][col]) != nullptr) {
                //TODO: Zufällige Floor-Textur
                tilePixmap = texturecontainer->getFloors()[0];
            }
            else if (dynamic_cast<Pit*>(level->getTilepointer()[row][col]) != nullptr) {
                tilePixmap = texturecontainer->getPits()[0];
            }
            else if (dynamic_cast<Portal*>(level->getTilepointer()[row][col]) != nullptr) {
                //TODO: Verbundene Portale sollen gleiche Farbe haben
                tilePixmap = texturecontainer->getPortals()[0];
            }
            else if (dynamic_cast<Ramp*>(level->getTilepointer()[row][col]) != nullptr) {
                tilePixmap = texturecontainer->getRamps()[0];
            }
            else if (dynamic_cast<Switch*>(level->getTilepointer()[row][col]) != nullptr) {
                tilePixmap = texturecontainer->getSwitches()[0];
            }
            else if (dynamic_cast<Wall*>(level->getTilepointer()[row][col]) != nullptr) {
                tilePixmap = texturecontainer->getWalls()[0];
            }
            else {
                tilePixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
            }

            QLabel* newTile = new QLabel();
            newTile->setScaledContents(true);
            newTile->setPixmap(tilePixmap);
            newTile->setMinimumSize(30, 30);
            newTile->setMaximumSize(30, 30);
            ui->gridLayout->addWidget(newTile, row, col);

            if (level->getTilepointer()[row][col]->hasCharacter()) {
                //QLabel* character = new QLabel();
                ui->characterLabel->setParent(newTile);
            }
        }
    }

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
}

void MainWindow::draw(Level* level, TextureContainer* texturecontainer) {
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

            if (currentTile->hasCharacter()) {
                QWidget* parentForCharacter = ui->gridLayout->itemAtPosition(row, col)->widget();
                QLabel* parentAsLabel = dynamic_cast<QLabel*>(parentForCharacter);

                //TODO: Komisch: Im Debugger erscheint der Character am richtigen Label als child, aber sichtbar ist er trotzdem nicht
                ui->characterLabel->setParent(parentAsLabel);
                ui->characterLabel->raise();
                ui->characterLabel->show();

                int characterMoveDirection = level->getCharacterpointer()[0]->getMoveDirection();

                if (characterMoveDirection == 7) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharBacks()[0]);
                }
                else if (characterMoveDirection == 8) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharBacks()[1]);
                }
                else if (characterMoveDirection == 9) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharBacks()[2]);
                }
                else if (characterMoveDirection == 6) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharRights()[0]);
                }
                else if (characterMoveDirection == 3) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharFronts()[0]);
                }
                else if (characterMoveDirection == 2) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharFronts()[1]);
                }
                else if (characterMoveDirection == 1) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharFronts()[2]);
                }
                else if (characterMoveDirection == 4) {
                    ui->characterLabel->setPixmap(texturecontainer->getCharLefts()[0]);
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
