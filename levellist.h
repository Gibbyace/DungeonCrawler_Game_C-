#ifndef LEVELLIST_H
#define LEVELLIST_H

#include "level.h"

class Level;

class LevelList
{

public:
    LevelList();
    ~LevelList();
    void push_back(Level* level);
    void push_front(Level* level);
    void pop_back();
    void pop_front();
    bool empty();
    size_t getSize() const;
    void remove(Level*);

    struct Element {
        Level* level;
        Element* prev;
        Element* next;
    };

    class iterator {
    public:
        Element* m_ptr;

        iterator(Element* ptr) {
            this->m_ptr = ptr;
        }

        iterator& operator++(int) {
            m_ptr = m_ptr->next;
            return *this;
        }

        iterator& operator--(int) {
            m_ptr = m_ptr->prev;
            return *this;
        }

        Element& operator*() const {
            return *m_ptr;
        }

        bool operator==(const iterator& b) {
            return m_ptr == b.m_ptr;
        }

        bool operator!=(const iterator& b) {
            return m_ptr != b.m_ptr;
        }
    };

    iterator begin();
    iterator end();

    void test();
    void print();

private:
    Element* start = nullptr;   //Pseudoelement, das den Anfang markiert
    Element* ending = nullptr;     //Pseudoelement, das das Ende markiert
    size_t size = 0;
};

#endif // LEVELLIST_H
