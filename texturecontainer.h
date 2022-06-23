#ifndef TEXTURES_H
#define TEXTURES_H

#include <vector>
#include <QPixmap>

using namespace std;

class TextureContainer
{
public:
    TextureContainer();


    vector<QPixmap> getBackgrounds() const;
    vector<QPixmap> getArrows() const;
    vector<QPixmap> getDoors() const;
    vector<QPixmap> getFloors() const;
    vector<QPixmap> getLevelchanger() const;
    vector<QPixmap> getLootChest() const;
    vector<QPixmap> getPits() const;
    vector<QPixmap> getPortals() const;
    vector<QPixmap> getRamps() const;
    vector<QPixmap> getSwitches() const;
    vector<QPixmap> getWalls() const;
    vector<QPixmap> getZombies() const;
    vector<QPixmap> getCharFronts() const;
    vector<QPixmap> getCharBacks() const;
    vector<QPixmap> getCharLefts() const;
    vector<QPixmap> getCharRights() const;

private:
    vector<QPixmap> backgrounds;
    vector<QPixmap> arrows;
    vector<QPixmap> doors;
    vector<QPixmap> floors;
    vector<QPixmap> levelchanger;
    vector<QPixmap> lootchest;
    vector<QPixmap> pits;
    vector<QPixmap> portals;
    vector<QPixmap> ramps;
    vector<QPixmap> switches;
    vector<QPixmap> walls;
    vector<QPixmap> zombies;

    vector<QPixmap> charFronts;
    vector<QPixmap> charBacks;
    vector<QPixmap> charLefts;
    vector<QPixmap> charRights;
};

#endif // TEXTURES_H
