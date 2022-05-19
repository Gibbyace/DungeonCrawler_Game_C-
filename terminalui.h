#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "abstractui.h"
#include "controller.h"

class TerminalUI : public AbstractUI, public Controller
        //Alle Ausgaben hier
{

public:
    TerminalUI();
    void draw(Level* level) override;
    void printDirectionOptions() override;
    int move() override;
};

#endif // TERMINALUI_H
