#include "terminalui.h"
#include "level.h"
#include "character.h"


TerminalUI::TerminalUI()
{

}

/*string TerminalUI::askUserForDirection() {
    string direction = "";

    while(true) {
        cout << "Wo willst du hin (up, down, left, right)?" << endl;
        cin >> direction;

        if (direction == "up" || direction == "down" || direction == "left" || direction == "right") {
            return direction;
        }

        cout << "Diese Richtung gibt es nicht." << endl;
    }
}*/

void TerminalUI::draw(Level* level) {
    for (int row = 0; row < level->getHeight(); row++) {
        for (int col = 0; col < level->getWidth(); col++) {
            cout << level->getTilepointer()[row][col]->getTexture() + " ";
        }

        cout << endl;
    }
}
