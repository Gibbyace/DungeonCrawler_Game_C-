#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "abstractui.h"

class TerminalUI : public AbstractUI
        //Alle Ausgaben hier
{

public:
    TerminalUI();
    void draw(Level* level) override;
    void printDirectionOptions() override;
};

#endif // TERMINALUI_H
