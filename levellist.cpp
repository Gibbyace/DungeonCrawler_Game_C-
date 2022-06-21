#include "levellist.h"

LevelList::LevelList()
{
    Element* startElement = new Element();
    Element* endElement = new Element();

    startElement->prev = nullptr;
    startElement->next = endElement;
    startElement->level = nullptr;

    endElement->prev = startElement;
    endElement->next = nullptr;
    endElement->level = nullptr;

    start = startElement;
    ending = endElement;
}

size_t LevelList::getSize() const
{
    return size;
}

bool LevelList::empty() {
    return size == 0;
}

void LevelList::push_back(Level* level) {
    Element* element = new Element();
    element->level = level;

    if (empty()) {
        element->prev = start;
        element->next = ending;

        start->next = element;
        ending->prev = element;
    }
    else {
        element->prev = ending->prev;
        element->next = ending;

        ending->prev->next = element;
        ending->prev = element;
    }

    size++;
}

void LevelList::push_front(Level* level) {
    Element* element = new Element();
    element->level = level;

    if (empty()) {
        element->prev = start;
        element->next = ending;

        start->next = element;
        ending->prev = element;
    }
    else {
        element->next = start->next;
        element->prev = start;

        start->next->prev = element;
        start->next = element;
    }

    size++;
}

void LevelList::pop_back() {
    if (empty()) {
        throw std::runtime_error("Versuch, Element aus leerer Liste zu entfernen");
    }

    Element* elementToDelete = ending->prev;

    ending->prev->prev->next = ending;
    ending->prev = ending->prev->prev;

    delete elementToDelete;

    size--;
}

void LevelList::pop_front() {
    if (empty()) {
        throw std::runtime_error("Versuch, Element aus leerer Liste zu entfernen");
    }

    Element* elementToDelete = start->next;

    start->next->next->prev = start;
    start->next = start->next->next;

    delete elementToDelete;

    size--;
}

void LevelList::remove(Level* level) {
    Element* current = start;

    while (current->next != nullptr) {
        if (current->level == level) {
            current->prev->next = current->next;
            current->next->prev = current->prev;

            delete current;

            size--;
        }

        current = current->next;
    }
}

LevelList::iterator LevelList::begin() {
    iterator it = iterator(start->next);
    return it;
}

LevelList::iterator LevelList::end() {
    iterator it = iterator(ending);
    return it;
}

void LevelList::print() {
    Element* current = start;

    cout << endl;

    while (current->next != nullptr) {
        cout << "Ein Durchgang ist geschafft " << endl;

        if (current->level != nullptr) {
            cout << "Das Level hat ne Id " << current->level->getId() << endl;
        }
        else {
            cout << "Aktuelle Element ist Nullpointer" << endl;
        }

        current = current->next;

        if (current == nullptr) {
            cout << "Das nächste Element ist Nullpointer" << endl;
        }
    }
}

void LevelList::test() {
    Level* level1 = new Level({
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", "l", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", "N", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", "e", ".", "#"},
                                  {"#", "_", "_", "<", ".", "X", ".", ".", ".", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  }, 10, 10);
    Level* level2 = new Level({
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", "l", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", "N", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", "e", ".", "#"},
                                  {"#", "_", "_", "<", ".", "X", ".", ".", ".", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  }, 10, 10);
    Level* level3 = new Level({
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", "l", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", "N", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", "e", ".", "#"},
                                  {"#", "_", "_", "<", ".", "X", ".", ".", ".", "#"},
                                  {"#", "_", "_", "_", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", ".", ".", ".", ".", ".", ".", ".", ".", "#"},
                                  {"#", "#", "#", "#", "#", "#", "#", "#", "#", "#"},
                                  }, 10, 10);

    push_back(level1);
    push_back(level2);
    push_back(level3);

    print();

    pop_back();
    print();

    push_back(level3);
    print();

    pop_front();
    print();

    push_front(level1);
    print();

    remove(level3);
    print();

    push_back(level3);
    print();

    cout << "Und jetzt iterieren wir einmal durch die Liste" << endl;

    for (iterator it = begin(); it.m_ptr != ending; it++) {
        cout << it.m_ptr->level->getId() << endl;
    }
}
