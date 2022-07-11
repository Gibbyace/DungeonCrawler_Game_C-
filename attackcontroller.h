#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "level.h"
#include "character.h"
#include "controller.h"
#include "graph.h"

class Attackcontroller : public Controller
{
private:
    Level* level;
    Character* controllingCharacter;
    Graph* graph;
    Tile* getTileWithPlayerCharacter();

public:
    Attackcontroller(Level* level, Character* controllingCharacter);
    int move() override;
};

#endif // ATTACKCONTROLLER_H
