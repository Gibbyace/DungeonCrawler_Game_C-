#ifndef LEVEL_H
#define LEVEL_H
#include "character.h"
#include "tile.h"
#include <vector>


class Level
{
    std::vector<std::vector<Tile*>>;
    std::vector<Character*>;
    const int height;
    const int width;


public:
    Level(const int height, const int width);
};

#endif // LEVEL_H
