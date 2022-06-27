#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H
#include "level.h"

#include "controller.h"

class Attackcontroller : public Controller
{
public:
    Attackcontroller();
    void getPathFromLevel(Level* level);

};

#endif // ATTACKCONTROLLER_H
