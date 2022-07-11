#ifndef LEVEL_H
#define LEVEL_H
#include "character.h"
#include "tile.h"
#include "levellist.h"
#include "levelchanger.h"
#include <vector>

using namespace std;

class LevelList;
class Levelchanger;

class Level
{
private:
    vector<Levelchanger*> levelchangers;
    vector<vector<Tile*>> tilepointer;
    vector<Character*> characterpointer;
    int height;
    int width;


public:
    static LevelList* generateLevels();

    static int idCounter;
    friend void swap(Level& lhs, Level& rhs);
    Level(vector<vector<string>>);
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
    void characterpointerpushback(Character* character);
    Character* getPlayerCharacter();
    Character* getNPCCharacter();
    bool operator ==(Level* rhs);
    int getId() const;
    void deleteCharacterById(int id);
    vector<Levelchanger *> getLevelchangers() const;

    void setId(int value);

    void placeCharacter(Character *c, int row, int col);
    void placePortals(int row1, int col1, int row2, int col2);
    void placeSwitchAndDoor(int row1, int col1, int row2, int col2);


    void setCharacterpointer(const vector<Character *> &newCharacterpointer);

    void setLevelchangers(const vector<Levelchanger *> &newLevelchangers);

    void setTilepointer(const vector<vector<Tile *> > &newTilepointer);

protected:
    int id;
};

#endif // LEVEL_H
