﻿#include "startscreen.h"
#include "ui_startscreen.h"
//#include <graphicalui.h>
StartScreen::StartScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{

    ui->setupUi(this);
    QWidget::setStyleSheet(("Background-color: black;"));

    QPixmap pixmapTarget = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/startscreen.png");
    ui->label->setPixmap(pixmapTarget);

    //können wa später vll noch dazu machen
    //QPixmap PixmapTarget3 = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/bloody_frame.png");
    //ui->label_2->setPixmap(PixmapTarget3);

    QIcon pixmapTarget2 = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/new_game_button.png");
    ui->pushButton->setIcon(pixmapTarget2);




}

StartScreen::~StartScreen()
{
    delete ui;

}

void StartScreen::on_pushButton_clicked()
{
    //ui->pushButton->hide();
    this->hide();

    /*GraphicalUI graphicalui = GraphicalUI(this->parent());
    graphicalui.show();*/
}
