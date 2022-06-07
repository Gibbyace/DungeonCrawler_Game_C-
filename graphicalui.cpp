#include "graphicalui.h"
#include "ui_graphicalui.h"
#include <startscreen.h>
#include <mainwindow.h>
#include <qtest.h>

GraphicalUI::GraphicalUI(Level* level, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicalUI)
{
    ui->setupUi(this);

    loadTextures();

    startscreen = new StartScreen(texturecontainer, this);

    mainwindow = new MainWindow(level, texturecontainer, this);    startscreen->exec();

//    mainwindow->show();

    //this->show();
}

GraphicalUI::~GraphicalUI()
{
    delete ui;
    delete mainwindow;
}

void GraphicalUI::draw(Level *level) {
    mainwindow->draw(level, texturecontainer);
}

int GraphicalUI::move() {
    QTest::qWait(50);
    QCoreApplication::processEvents();

    if (inputProcessed == false) {
        inputProcessed = true;
        return lastInput;
    }

    return 5;
}

void GraphicalUI::hide_startscreen_and_show_mainwindow() {
    qDebug("Heyyy, der hide_startscreen_and_show_mainwindow-Slot wurde aufgerufen!");

    startscreen->hide();

    /*
     * eigentlich sollte das mainwindow hier aktiviert werden,
     * dann entsteht aber ein SEGFAULT,
     * also ist das momentan noch im Konstruktor
     * TODO: Dafür sorgen, dass das mainwindow von hier erzeugt wird
    */
    mainwindow->show();
}

void GraphicalUI::setLastInput(int direction) {
    lastInput = direction;
    inputProcessed = false;
}

void GraphicalUI::loadTextures() {
    texturecontainer = new TextureContainer();
}
