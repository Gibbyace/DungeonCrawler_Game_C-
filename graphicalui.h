#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QWidget>
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

class GraphicalUI : public QWidget, public AbstractUI, public Controller
{
    Q_OBJECT

public:
    explicit GraphicalUI(Level* level, QWidget *parent = nullptr);
    ~GraphicalUI();
    void draw(Level *level) override;
    int move() override;
    void loadTextures();

    //bool getInputProcessed() const;
    //void setInputProcessed(bool value);

public slots:
    void windowHasBeenClosed();
    void setLastInput(int direction);
    void hide_startscreen_and_show_mainwindow();

private:
    MainWindow* mainwindow;
    StartScreen* startscreen;
    TextureContainer* texturecontainer;
    int lastInput = 5;
    //bool inputProcessed = true;
};

#endif // GRAPHICALUI_H
