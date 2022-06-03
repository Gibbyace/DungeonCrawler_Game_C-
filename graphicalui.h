﻿#ifndef GRAPHICALUI_H
#define GRAPHICALUI_H

#include <QMainWindow>
#include <abstractui.h>
#include <controller.h>
#include <array>


class GraphicalUI : public QMainWindow, public AbstractUI, public Controller
{
    Q_OBJECT
public:
    explicit GraphicalUI(QWidget *parent = nullptr);
    void draw(Level* level) override;
    int move() override;
    void textureloading();

    array <QPixmap, 6> startscreen;

    array <QPixmap, 8> arrow;
    array <QPixmap, 2> door;
    array <QPixmap, 5> floor;
    array <QPixmap, 3> portal;
    array <QPixmap, 1> wall;
    array <QPixmap, 2> zombie;



    array <QPixmap, 3> char_front;
    array <QPixmap, 3> char_back;
    array <QPixmap, 3> char_left;
    array <QPixmap, 3> char_right;







signals:

};

#endif // GRAPHICALUI_H
