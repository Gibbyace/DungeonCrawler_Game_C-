#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <abstractui.h>
#include <controller.h>
#include <level.h>

namespace Ui {
class GraphicalUI;
}

class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT

public:
    GraphicalUI(QWidget *parent = nullptr);
    ~GraphicalUI();

    void draw(Level *level) override;
    int move() override;

    //Public slot soll hier rein für button push

private:
    Ui::GraphicalUI *ui;
};

#endif // GRAPHICALUI_H
