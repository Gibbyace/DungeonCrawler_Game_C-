#include <iostream>
#include "guardcontroller.h"

GuardController::GuardController(vector<int> pattern)
{
    this->pattern = pattern;
    this->patternIndex = 0;
}

int GuardController::move() {
    patternIndex++;

    if (patternIndex >= pattern.size()) {
        patternIndex = 0;
    }

    return pattern[patternIndex];
}
