#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
#include <level.h>


class AbstractUI
{

public:
    //Alle ausgaben sind hier zu verzeichnen und zu kapseln
    AbstractUI();
    virtual void draw(Level* level) = 0;

};

#endif // ABSTRACTUI_H
