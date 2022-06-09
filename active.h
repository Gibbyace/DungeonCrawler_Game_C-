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
    void attach(Passive*);
    void detach(Passive*);
    void activate();

    vector<Passive *> getObservers() const;
};

#endif // ACTIVE_H
