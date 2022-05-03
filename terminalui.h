#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "klassabstractui.h"

class TerminalUI : public KlassAbstractUI
        //Alle Ausgaben hier
{

public:
    TerminalUI();
    void draw(Level*) override;

};

#endif // TERMINALUI_H
