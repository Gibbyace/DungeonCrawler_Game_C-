#ifndef LEVEL_H
#define LEVEL_H
#include "character.h"
#include "tile.h"
#include <vector>

using namespace std;

class Level
{
    vector<vector<Tile*>> tilepointer;
    vector<Character*> characterpointer;
    int height;
    int width;


public:
    static int idCounter;
    friend void swap(Level& lhs, Level& rhs);
    Level(const int height, const int width);
    Level(const Level& level);
    Level& operator=(const Level rhs);
    ~Level();
    Tile *getTile(int row, int col);
    Tile *getLootChest(int row, int col);
    const Tile *getTile(int row, int col) const;
    const vector<vector<Tile *> > &getTilepointer() const;
    int getHeight() const;
    int getWidth() const;
    const vector<Character *> &getCharacterpointer() const;
    Character* getPlayerCharacter();


    int getId() const;

protected:
    int id;
    void placeCharacter(Character *c, int row, int col);
    void placePortals(int row1, int col1, int row2, int col2);
    void placeSwitchAndDoor(int row1, int col1, int row2, int col2);
};

#endif // LEVEL_H
