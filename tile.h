#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Character;

class Tile
{
protected:
  string texture;
  Character* character = nullptr;
  const int row;
  const int column;


public:
    Tile(int row, int column);
    string getTexture();
    bool hasCharacter();
    bool moveTo(Tile* fromTile, Character* who);
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;
    virtual ~Tile() = default;

    //void battle(Character* attacker, Character* defender);

    void setCharacter(Character *newCharacter);
    int getRow() const;
    int getColumn() const;
    Character *getCharacter() const;
};

#endif // TILE_H
