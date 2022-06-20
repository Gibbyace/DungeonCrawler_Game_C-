#include "endscreen.h"
#include "ui_endscreen.h"
#include "mainwindow.h"
#include "graphicalui.h"
#include "texturecontainer.h"


class GraphicalUI;
class TextureContainer;

endscreen::endscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endscreen)
{
    ui->setupUi(this);
    //TODO implementation von scaled bild

}

endscreen::~endscreen()
{
    delete ui;
}

bool endscreen::buttonboxpressed() {



}
