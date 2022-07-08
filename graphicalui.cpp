#include "graphicalui.h"
#include <startscreen.h>
#include <mainwindow.h>
#include <qtest.h>

GraphicalUI::GraphicalUI(Level* level, QWidget *parent)
{
    loadTextures();

    inputProcessed = true;

    startscreen = new StartScreen(texturecontainer, this);
    mainwindow = new MainWindow(level, texturecontainer, this);

    startscreen->show();
}

GraphicalUI::~GraphicalUI()
{
    delete mainwindow;
    delete startscreen;
    delete texturecontainer;
}

void GraphicalUI::draw(Level *level) {
    mainwindow->draw(level, texturecontainer);
}

int GraphicalUI::move() {
    QTest::qWait(50);
    QCoreApplication::processEvents();

    if (inputProcessed == false) {
        return lastInput;
    }

    return 5;
}

void GraphicalUI::hide_startscreen_and_show_mainwindow() {
    startscreen->hide();
    mainwindow->show();
}

TextureContainer *GraphicalUI::getTexturecontainer() const
{
    return texturecontainer;
}

MainWindow *GraphicalUI::getMainwindow() const
{
    return mainwindow;
}

void GraphicalUI::setLastInput(int direction) {
    lastInput = direction;
    inputProcessed = false;
    mainwindow->setChangesDrawn(false);
}

void GraphicalUI::windowHasBeenClosed() {
    qDebug("shit, ne warte, das ist gut");
    this->setUserWantsToEndThisApp(true);
}

void GraphicalUI::loadTextures() {
    texturecontainer = new TextureContainer();
}

