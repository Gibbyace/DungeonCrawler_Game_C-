#include "startscreen.h"
#include "ui_startscreen.h"
//#include <graphicalui.h>
#include <dungeoncrawler.h>

StartScreen::StartScreen(/*GraphicalUI* graphicalui, */QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{

    ui->setupUi(this);
    QWidget::setStyleSheet(("Background-color: black;"));

    //TODO: Laden bitte pers graphical UI umändern
    QPixmap pixmapTarget = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/startscreen.png");
    ui->label->setPixmap(pixmapTarget);

    //können wa später vll noch dazu machen
    //QPixmap PixmapTarget3 = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/bloody_frame.png");
    //ui->label_2->setPixmap(PixmapTarget3);

    QIcon pixmapTarget2 = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/new_game_button.png");
    ui->pushButton->setIcon(pixmapTarget2);

    //wie bekommen wir hier unser GraphicalUI-Objekt rein?
    //connect(ui->pushButton, &QPushButton::clicked, this, &GraphicalUI::hide_startscreen_and_show_graphicalui);
}

StartScreen::~StartScreen()
{
    delete ui;

}

void StartScreen::on_pushButton_clicked()
{
    //ui->pushButton->hide();
    this->hide();
}
