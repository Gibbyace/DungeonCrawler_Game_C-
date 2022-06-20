#ifndef LEVELLIST_H
#define LEVELLIST_H

#include "level.h"

class LevelList
{

public:
    LevelList();
    void push_back(Level* level);
    void push_front(Level* level);
    void pop_back();
    void pop_front();
    bool empty();
    size_t getSize() const;
    void remove(Level*);
    //iterator begin();
    //iterator end();
    void test();

private:
    struct Element {
        Level* level;
        Element* prev;
        Element* next;
    };

    Element* start = nullptr;   //Pseudoelement, das den Anfang markiert
    Element* end = nullptr;     //Pseudoelement, das das Ende markiert
    size_t size = 0;
};

#endif // LEVELLIST_H
