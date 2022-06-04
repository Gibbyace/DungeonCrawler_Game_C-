#include "graphicalui.h"
#include "ui_graphicalui.h"
#include "startscreen.h"

GraphicalUI::GraphicalUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicalUI)
{
    ui->setupUi(this);

    StartScreen startscreen;
    startscreen.exec();

    this->show();
}

GraphicalUI::~GraphicalUI()
{
    delete ui;
}

void GraphicalUI::draw(Level *level) {

}

int GraphicalUI::move() {
    return 5;
}
