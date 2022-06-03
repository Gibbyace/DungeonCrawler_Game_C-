#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <abstractui.h>
#include <controller.h>

class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT
public:
    explicit GraphicalUI(QWidget *parent = nullptr);
    void draw(Level* level) override;
    int move() override;

signals:

};

#endif // GRAPHICALUI_H
