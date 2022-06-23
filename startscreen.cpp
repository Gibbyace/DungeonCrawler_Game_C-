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

    connect(ui->pushButton, &QPushButton::clicked, parent, &GraphicalUI::hide_startscreen_and_show_mainwindow);
}

StartScreen::~StartScreen()
{
    delete ui;
}
