#include "terminalui.h"
#include "level.h"
#include "character.h"


TerminalUI::TerminalUI()
{

}

void TerminalUI::draw(Level* level) {
    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            cout << level->getTilepointer()[row][col]->getTexture() + " ";
        }

        cout << endl;
    }
}
