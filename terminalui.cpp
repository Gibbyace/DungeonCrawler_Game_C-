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

    cout << endl;
}

void TerminalUI::printDirectionOptions()
{
    cout << "Where do you want to go?" << endl;
    cout << "1: Down-Right" << endl;
    cout << "2: Down" << endl;
    cout << "3: Down-Right" << endl;
    cout << "4: Left" << endl;
    cout << "5: Stay" << endl;
    cout << "6: Right" << endl;
    cout << "7: Left-Up" << endl;
    cout << "8: Up" << endl;
    cout << "9: Up-Right" << endl;
    cout << "0: Close Game" << endl;
    cout << endl;
}

int TerminalUI::move(){
    while (true) {
        char input;

        cin >> input;

        if (input >= 48 && input <= 58) {
            return input - 48;
        }
        else {
            cout << "This is not an option" << endl << endl;
            return 5;
        }
    }
}
