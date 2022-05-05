#ifndef KLASSABSTRACTUI_H
#define KLASSABSTRACTUI_H
#include <level.h>


class KlassAbstractUI
{

public:
    //Alle ausgaben sind hier zu verzeichnen und zu kapseln
    KlassAbstractUI();
    virtual void draw(Level*)=0;

};

#endif // KLASSABSTRACTUI_H
