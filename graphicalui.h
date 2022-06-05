#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <abstractui.h>
#include <controller.h>
#include <startscreen.h>

namespace Ui {
class GraphicalUI;
}

class StartScreen;

class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT

public:
    explicit GraphicalUI(QWidget *parent = nullptr);
    ~GraphicalUI();
    void draw(Level *level) override;
    int move() override;

public slots:
    void hide_startscreen_and_show_graphicalui();

private:
    Ui::GraphicalUI *ui;
};

#endif // GRAPHICALUI_H
