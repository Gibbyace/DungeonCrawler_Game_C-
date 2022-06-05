#include "graphicalui.h"
#include "ui_graphicalui.h"
#include <startscreen.h>
#include <mainwindow.h>

GraphicalUI::GraphicalUI(Level* level, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicalUI)
{
    ui->setupUi(this);

    textureloading();

    MainWindow* mainwindow = new MainWindow(level, this);
    mainwindow->show();

    /*StartScreen startscreen = StartScreen(this, parent);
    startscreen.exec();*/

    this->show();
}

GraphicalUI::~GraphicalUI()
{
    delete ui;
}

void GraphicalUI::draw(Level *level) {

}

int GraphicalUI::move() {
    return 5;
}

void GraphicalUI::hide_startscreen_and_show_graphicalui() {
    cout << "Hey, ich wurde aufgerufen!";
}

void GraphicalUI::setLastInput(int direction) {
    cout << direction;
}

void GraphicalUI::textureloading() {
    //von unten im uhrzeigersinn bis zu letzttem element skip
    arrow[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down.png");
    arrow[1] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down_left.png");
    arrow[2] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_left.png");
    arrow[3] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up_left.png");
    arrow[4] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up.png");
    arrow[5] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_up_right");
    arrow[6] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_right.png");
    arrow[7] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_down_right");
    arrow[8] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/arrows/arrow_skip.png");

    door[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/doors/door1.png");
    door[1] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/doors/door2.png");

    floor[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor1.png");
    floor[1] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor2.png");
    floor[2] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor3.png");
    floor[3] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor4.png");
    floor[4] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/floor/floor5.png");

    portal[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/portal/portal1.png");
    portal[1] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/portal/portal2.png");
    portal[2] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/portal/portal3.png");

    wall[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/wall/wall1.png");

    zombie[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/zombie/zombie_left.png");
    zombie[0] = QPixmap("../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/zombie/zombie_right.png");

    char_back[0] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_1.png");
    char_back[1] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_2.png");
    char_back[2] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/back/char_back_3.png");

    char_front[0] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_1.png");
    char_front[1] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_2.png");
    char_front[2] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/front/char_front_3.png");

    char_left[0] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/left/char_left_1.png");
    char_left[1] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/left/char_left_2.png");
    char_left[2] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/left/char_left_3.png");

    char_right[0] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/right/char_right_1.png");
    char_right[1] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/right/char_right_2.png");
    char_right[2] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/char/right/char_right_3.png");

    startscreen[0] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/bloody_frame.png");
    startscreen[1] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/new_game_button.png");
    startscreen[2] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/pit.png");
    startscreen[3] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/ramp.png");
    startscreen[4] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/startscreen.png");
    startscreen[5] = QPixmap("..../pg2_Di45y-TeamA-Herrmann_Kotwal/textures/switch.png");
}
