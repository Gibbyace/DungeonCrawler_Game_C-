#ifndef TERMINALUI_H
#define TERMINALUI_H

#include "klassabstractui.h"

class TerminalUI : public KlassAbstractUI
        //Alle Ausgaben hier
{

public:
    TerminalUI();
    //string askUserForDirection();
    void draw(Level*) override;

};

#endif // TERMINALUI_H
