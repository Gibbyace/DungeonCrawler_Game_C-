#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <abstractui.h>
#include <controller.h>
#include <startscreen.h>
#include <mainwindow.h>
#include <texturecontainer.h>

namespace Ui {
class GraphicalUI;
}

class StartScreen;
class MainWindow;

#include <vector>

class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT

public:
    explicit GraphicalUI(Level* level, QWidget *parent = nullptr);
    ~GraphicalUI();
    void draw(Level *level) override;
    int move() override;
    void loadTextures();

public slots:
    void setLastInput(int direction);
    void hide_startscreen_and_show_mainwindow();

private:
    Ui::GraphicalUI *ui;
    MainWindow* mainwindow;
    StartScreen* startscreen;
    TextureContainer* texturecontainer;
    int lastInput = 5;
    bool inputProcessed = false;
};

#endif // GRAPHICALUI_H
