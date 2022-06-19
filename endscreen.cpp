#include "endscreen.h"
#include "ui_endscreen.h"
#include "mainwindow.h"

endscreen::endscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endscreen)
{
    ui->setupUi(this);

}

endscreen::~endscreen()
{
    delete ui;
}

bool endscreen::buttonboxpressed() {


}
