#ifndef TEXTURES_H
#define TEXTURES_H

#include <vector>
#include <QPixmap>

using namespace std;

class TextureContainer
{
public:
    TextureContainer();

private:
    vector<QPixmap> backgrounds;
    vector<QPixmap> arrows;

    vector<QPixmap> doors;
    vector<QPixmap> floors;
    vector<QPixmap> pits;
    vector<QPixmap> portals;
    vector<QPixmap> ramps;
    vector<QPixmap> switches;
    vector<QPixmap> walls;
    vector<QPixmap> zombies;

    vector<QPixmap> char_fronts;
    vector<QPixmap> char_backs;
    vector<QPixmap> char_lefts;
    vector<QPixmap> char_rights;
};

#endif // TEXTURES_H
