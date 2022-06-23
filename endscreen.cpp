#include "endscreen.h"
#include "ui_endscreen.h"
#include "mainwindow.h"
#include "graphicalui.h"
#include "texturecontainer.h"


class GraphicalUI;
class TextureContainer;

Endscreen::Endscreen(QString message, TextureContainer* texturecontainer, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endscreen)
{
    ui->setupUi(this);
    //TODO implementation von scaled bild

    ui->backgroundLabel->setPixmap(texturecontainer->getBackgrounds()[3]);

    ui->messageLabel->setStyleSheet(("color: #FFF"));
    ui->messageLabel->setText(message);

}

Endscreen::~Endscreen()
{
    delete ui;
}

bool Endscreen::buttonboxpressed() {



}
