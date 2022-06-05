#include "texturecontainer.h"

TextureContainer::TextureContainer()
{
    QString imageDirectory = "../pg2_Di45y-TeamA-Herrmann_Kotwal/textures";

    //von unten im Uhrzeigersinn bis zu letztem element Skip
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_down.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_down_left.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_left.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_up_left.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_up.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_up_right"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_right.png"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_down_right"));
    arrows.push_back(QPixmap(imageDirectory + "/arrows/arrow_skip.png"));

    doors.push_back(QPixmap(imageDirectory + "/doors/door1.png"));
    doors.push_back(QPixmap(imageDirectory + "/doors/door2.png"));

    floors.push_back(QPixmap(imageDirectory + "/floor/floor1.png"));
    floors.push_back(QPixmap(imageDirectory + "/floor/floor2.png"));
    floors.push_back(QPixmap(imageDirectory + "/floor/floor3.png"));
    floors.push_back(QPixmap(imageDirectory + "/floor/floor4.png"));
    floors.push_back(QPixmap(imageDirectory + "/floor/floor5.png"));

    pits.push_back(QPixmap(imageDirectory + "/pit.png"));

    portals.push_back(QPixmap(imageDirectory + "/portal/portal1.png"));
    portals.push_back(QPixmap(imageDirectory + "/portal/portal2.png"));
    portals.push_back(QPixmap(imageDirectory + "/portal/portal3.png"));

    ramps.push_back(QPixmap(imageDirectory + "/ramp.png"));

    switches.push_back(QPixmap(imageDirectory + "/switch.png"));

    walls.push_back(QPixmap(imageDirectory + "/wall/wall1.png"));

    zombies.push_back(QPixmap(imageDirectory + "/zombie/zombie_left.png"));
    zombies.push_back(QPixmap(imageDirectory + "/zombie/zombie_right.png"));

    char_backs.push_back(QPixmap(imageDirectory + "/char/back/char_back_1.png"));
    char_backs.push_back(QPixmap(imageDirectory + "/char/back/char_back_2.png"));
    char_backs.push_back(QPixmap(imageDirectory + "/char/back/char_back_3.png"));

    char_fronts.push_back(QPixmap(imageDirectory + "/char/front/char_front_1.png"));
    char_fronts.push_back(QPixmap(imageDirectory + "/char/front/char_front_2.png"));
    char_fronts.push_back(QPixmap(imageDirectory + "/char/front/char_front_3.png"));

    char_lefts.push_back(QPixmap(imageDirectory + "/char/left/char_left_1.png"));
    char_lefts.push_back(QPixmap(imageDirectory + "/char/left/char_left_2.png"));
    char_lefts.push_back(QPixmap(imageDirectory + "/char/left/char_left_3.png"));

    char_rights.push_back(QPixmap(imageDirectory + "/char/right/char_right_1.png"));
    char_rights.push_back(QPixmap(imageDirectory + "/char/right/char_right_2.png"));
    char_rights.push_back(QPixmap(imageDirectory + "/char/right/char_right_3.png"));

    backgrounds.push_back(QPixmap(imageDirectory + "/bloody_frame.png"));
    backgrounds.push_back(QPixmap(imageDirectory + "/new_game_button.png"));
    backgrounds.push_back(QPixmap(imageDirectory + "/startscreen.png"));
}
