#ifndef GUARDCONTROLLER_H
#define GUARDCONTROLLER_H

#include <vector>
#include "controller.h"

using namespace std;

class GuardController : public Controller
{
public:
    GuardController(vector<int> pattern);
    int move() override;

private:
    vector<int> pattern;
    unsigned patternIndex = 0;
};

#endif // GUARDCONTROLLER_H
