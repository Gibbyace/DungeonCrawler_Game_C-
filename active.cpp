#include "active.h"
#include "passive.h"
Active::Active()
{

}

void Active::attach(Passive* passiveTile) {
    //TODO: prüfen, ob das schief geht
    for (unsigned i = 0; i < observers.size(); i++) {
        if (observers[i] == passiveTile) {
            return;
        }
    }

    observers.push_back(passiveTile);
}

void Active::detach(Passive* passiveTile) {
    for (unsigned i = 0; i < observers.size(); i++) {
        if (observers[i] == passiveTile) {
            observers.erase(observers.begin()+i);
        }
    }
}

void Active::activate(){
    for (unsigned i = 0; i < observers.size(); i++) {
        observers[i]->notify(this);
    }
}
