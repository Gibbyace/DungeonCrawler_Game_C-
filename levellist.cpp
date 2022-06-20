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
        cout << "Liste ist leer" << endl;
        element->prev = start;
        element->next = end;

        start->next = element;
        end->prev = element;
    }
    else {
        cout << "Liste ist nicht leer" << endl;
        element->prev = end->prev;
        element->next = end;

        end->prev->next = element;
        end->prev = element;
        //DAS NEXT VON DEM ELEMENT VOR END MUSS GESETZT WERDEN
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

        start->next->prev = element;
        start->next = element;
        //MUSS DAS PREV VON DEM ELEMENT NACH START GESETZT WERDEN? JA ODER?
    }

    size++;
}

void LevelList::test() {
    Level* level1 = new Level(10, 10);
    Level* level2 = new Level(10, 10);
    Level* level3 = new Level(10, 10);

    push_back(level1);
    push_back(level2);
    push_back(level3);

    Element* current = start;

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
