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

MainWindow::MainWindow(Level* level, GraphicalUI *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget::setStyleSheet(("Background-color: black;"));

    QPixmap pixmapTarget = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/bloody_frame.png");
    ui->label->setPixmap(pixmapTarget);
    ui->label->setScaledContents(true);

    ui->characterLabel->setScaledContents(true);
    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_2.png"));
    ui->characterLabel->setMinimumSize(30, 30);
    ui->characterLabel->setMaximumSize(30, 30);

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            QPixmap floorPixmap;

            if (dynamic_cast<Door*>(level->getTilepointer()[row][col]) != nullptr) {
                //TODO: Zustand der Tür beachten
                 floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/doors/door1.png");
            }
            else if (dynamic_cast<Floor*>(level->getTilepointer()[row][col]) != nullptr) {
                //TODO: Zufällige Floor-Textur
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
            }
            else if (dynamic_cast<Pit*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/pit.png");
            }
            else if (dynamic_cast<Portal*>(level->getTilepointer()[row][col]) != nullptr) {
                //TODO: Verbundene Portale sollen gleiche Farbe haben
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/portal/portal1.png");
            }
            else if (dynamic_cast<Ramp*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/ramp.png");
            }
            else if (dynamic_cast<Switch*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/switch.png");
            }
            else if (dynamic_cast<Wall*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/wall/wall1.png");
            }
            else {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
            }

            QLabel* newTile = new QLabel();
            newTile->setScaledContents(true);
            newTile->setPixmap(floorPixmap);
            newTile->setMinimumSize(30, 30);
            newTile->setMaximumSize(30, 30);
            ui->gridLayout->addWidget(newTile, row, col);

            if (level->getTilepointer()[row][col]->hasCharacter()) {
                //QLabel* character = new QLabel();
                ui->characterLabel->setParent(newTile);
            }
        }
    }

    ui->topleftbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up_left.png"));
    ui->topbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up.png"));
    ui->toprightbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up_right.png"));
    ui->rightbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_right.png"));
    ui->bottomrightbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down_right.png"));
    ui->bottombutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down.png"));
    ui->bottomleftbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down_left.png"));
    ui->leftbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_left.png"));
    ui->centerbutton->setIcon(QIcon("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_skip.png"));

    connect(ui->topleftbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(7);});
    connect(ui->topbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(8);});
    connect(ui->toprightbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(9);});
    connect(ui->rightbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(6);});
    connect(ui->bottomrightbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(3);});
    connect(ui->bottombutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(2);});
    connect(ui->bottomleftbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(1);});
    connect(ui->leftbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(4);});
    connect(ui->centerbutton, &QPushButton::clicked, [parent](int direction) {parent->setLastInput(5);});
}

void MainWindow::draw(Level* level) {
    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getHeight(); col++) {
            if (level->getTilepointer()[row][col]->hasCharacter()) {
                QWidget* parentForCharacter = ui->gridLayout->itemAtPosition(row, col)->widget();

                //delete ui->characterLabel;
                //ui->characterLabel = new QLabel();

                //ui->characterLabel->setScaledContents(true);
                //ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_2.png"));
                //ui->characterLabel->setMinimumSize(30, 30);
                //ui->characterLabel->setMaximumSize(30, 30);

                //ui->characterLabel->setParent(parentForCharacter);
                ui->characterLabel->raise();

                int characterMoveDirection = level->getCharacterpointer()[0]->getMoveDirection();

                if (characterMoveDirection == 7) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_1.png"));
                }
                else if (characterMoveDirection == 8) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_2.png"));
                }
                else if (characterMoveDirection == 9) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_3.png"));
                }
                else if (characterMoveDirection == 6) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/right/char_right_1.png"));
                }
                else if (characterMoveDirection == 3) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_1.png"));
                }
                else if (characterMoveDirection == 2) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_2.png"));
                }
                else if (characterMoveDirection == 1) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_3.png"));
                }
                else if (characterMoveDirection == 4) {
                    ui->characterLabel->setPixmap(QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/left/char_left_2.png"));
                }
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
