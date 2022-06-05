#include "startscreen.h"
#include "ui_startscreen.h"
#include <dungeoncrawler.h>

StartScreen::StartScreen(TextureContainer* texturecontainer, GraphicalUI *parent) :
    QDialog(parent),
    ui(new Ui::StartScreen)
{

    ui->setupUi(this);
    QWidget::setStyleSheet(("Background-color: black;"));

    QPixmap startscreenBackground = texturecontainer->getBackgrounds()[2];
    ui->label->setPixmap(startscreenBackground);
    ui->label->setScaledContents(true);

    QIcon newGameBackground = texturecontainer->getBackgrounds()[1];
    ui->pushButton->setIcon(newGameBackground);

    //wie bekommen wir hier unser GraphicalUI-Objekt rein?
    connect(ui->pushButton, &QPushButton::clicked, parent, &GraphicalUI::hide_startscreen_and_show_mainwindow);
    //connect(ui->pushButton, &QPushButton::clicked, [parent]() {parent->hide_startscreen_and_show_mainwindow();});
}

StartScreen::~StartScreen()
{
    delete ui;

}

/*void StartScreen::on_pushButton_clicked()
{
    //ui->pushButton->hide();
    this->hide();
}*/
