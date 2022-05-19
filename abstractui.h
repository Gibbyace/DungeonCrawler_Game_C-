#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H
#include <level.h>


class AbstractUI
{

public:
    //Alle ausgaben sind hier zu verzeichnen und zu kapseln
    AbstractUI();
    virtual ~AbstractUI() = default;
    virtual void draw(Level* level) = 0;
    virtual void printDirectionOptions();
};

#endif // ABSTRACTUI_H
