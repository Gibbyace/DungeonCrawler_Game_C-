#include "levellist.h"

LevelList::LevelList()
{
    Element* startElement = new Element();
    startElement->prev = nullptr;
    startElement->next = nullptr;
    startElement->level = nullptr;

    Element* endElement = new Element();
    endElement->prev = nullptr;
    endElement->next = nullptr;
    endElement->level = nullptr;

    start = startElement;
    end = endElement;
}

size_t LevelList::getSize() const
{
    return size;
}

bool LevelList::empty() {
    return size == 0;
}

//wie teste ich diesen Stuss?
//ich könnte den Levels eine eindeutige ID mit nem static idCounter geben
//und dann mit einer LevelList::print Methode die IDs der Levels in der Liste ausgeben lassen

void LevelList::push_back(Level* level) {
    cout << "wir wollen das Level mit der id" << level->getId() << "pushen" << endl;

    Element* element = new Element();
    element->level = level;

    if (empty()) {
        cout << "Liste ist leer";
        element->prev = start;
        element->next = end;

        start->next = element;
        end->prev = element;
    }
    else {
        element->prev = end->prev;
        element->next = end;

        end->prev = element;
    }

    size++;
}

void LevelList::push_front(Level* level) {
    Element* element = new Element();
    element->level = level;

    if (empty()) {
        element->prev = start;
        element->next = end;

        start->next = element;
        end->prev = element;
    }
    else {
        element->next = start->next;
        element->prev = start;

        start->next = element;
    }

    size++;
}

void LevelList::test() {
    Level* level1 = new Level(10, 10);
    Level* level2 = new Level(10, 10);

    push_back(level1);
    push_back(level2);

    Element* current = start;

    cout << current->next->level->getId();

    while (current->next != nullptr) {
        cout << "Ein Durchgang ist geschafft " << endl;

        if (current->level != nullptr) {
            cout << "Das LEvel hat ne Id " << endl;
            cout << current->level->getId() << endl;
        }

        current = current->next;
    }
}
