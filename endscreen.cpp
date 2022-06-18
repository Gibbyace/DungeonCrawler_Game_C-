#include "endscreen.h"
#include "ui_endscreen.h"

endscreen::endscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::endscreen)
{
    ui->setupUi(this);
    QWidget::setStyleSheet(("Background-color: #030306;"));
}

endscreen::~endscreen()
{
    delete ui;
}

