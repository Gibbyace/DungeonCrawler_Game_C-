#ifndef PASSIVE_H
#define PASSIVE_H
#include "active.h"


class Passive
{
public:
    Passive();
    virtual void notify(Active* source) = 0;
};

#endif // PASSIVE_H
