#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "abstractui.h"
#include "controller.h"

class TerminalUI : public AbstractUI, public Controller
{

public:
    TerminalUI();
    ~TerminalUI() override = default;
    void draw(Level* level) override;
    void printDirectionOptions() override;
    int move() override;
};

#endif // TERMINALUI_H
