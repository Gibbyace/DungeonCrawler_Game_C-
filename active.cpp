#include "active.h"
#include "passive.h"
#include "dungeoncrawler.h"

vector<Passive *> Active::getObservers() const
{
    return observers;
}

Active::Active()
{

}

Active::~Active() {
    while (!observers.empty()) {
        //( ͡° ͜ʖ ͡°) Wir mögen es schmutzig
        if (dynamic_cast<DungeonCrawler*>(observers.back()) == nullptr) {
            delete observers.back();
        }

        observers.pop_back();
    }
}

void Active::attach(Passive* passiveTile) {
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
