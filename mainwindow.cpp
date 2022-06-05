#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <door.h>
#include <floor.h>
#include <pit.h>
#include <portal.h>
#include <ramp.h>
#include <switch.h>
#include <wall.h>

MainWindow::MainWindow(Level* level, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QWidget::setStyleSheet(("Background-color: black;"));

    //QPixmap pixmapTarget = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/bloody_frame.png");
    //ui->label->setPixmap(pixmapTarget);

    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            QPixmap floorPixmap;

            if (dynamic_cast<Door*>(level->getTilepointer()[row][col]) != nullptr) {
                 floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/doors/door1.png");
            }
            else if (dynamic_cast<Floor*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
            }
            else if (dynamic_cast<Pit*>(level->getTilepointer()[row][col]) != nullptr) {
                floorPixmap = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/pit.png");
            }
            else if (dynamic_cast<Portal*>(level->getTilepointer()[row][col]) != nullptr) {
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
        }
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
