#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>

using namespace  std;

class Passive;

//Implementation of concept
//bestitzt pointer auf sich selbst
class Active
{
protected:
    vector<Passive*> observers;

public:
    Active();
    void attach(Passive*); //method for adding passive objects
    void detach(Passive*); //gegenteil
    void activate();

    vector<Passive *> getObservers() const;
};

#endif // ACTIVE_H
