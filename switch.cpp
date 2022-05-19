#include "switch.h"

Switch::Switch(int row, int column): Active(), Tile(row, column)
{
    this->texture = "?";
}
