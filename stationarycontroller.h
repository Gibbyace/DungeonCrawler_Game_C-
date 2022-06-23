#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

#include "controller.h"

class StationaryController : public Controller
{
public:
    StationaryController();
    int move() override;
};

#endif // STATIONARYCONTROLLER_H
