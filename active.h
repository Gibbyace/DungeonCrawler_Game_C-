#ifndef ACTIVE_H
#define ACTIVE_H
#include <vector>

using namespace  std;

class Passive;

class Active
{
protected:
    vector<Passive*> observers;

public:
    Active();
    virtual ~Active() = default;
    void attach(Passive*);
    void detach(Passive*);
    void activate();

    vector<Passive*> getObservers() const;
};

#endif // ACTIVE_H
