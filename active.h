#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>


class Passive;

//Implementation of concept
//bestitzt pointer auf sich selbst
class Active
{
    std::vector<Passive*> observers;

public:
    Active();
    void attach(Passive*); //method for adding passive objects
    void detach(Passive*); //gegenteil
    void activate();

};

#endif // ACTIVE_H
