#include "graphicalui.h"
#include "ui_graphicalui.h"

GraphicalUI::GraphicalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphicalUI)
{
    ui->setupUi(this);
}

GraphicalUI::~GraphicalUI()
{
    delete ui;
}
