#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>
#include "passive.h"

//Implementation of concept
//bestitzt pointer auf sich selbst
class Active
{
    std::vector<Passive*> observers;

public:
    Active();
    void attach(Passive*);
    void detach(Passive*);
    void activate();

};

#endif // ACTIVE_H
