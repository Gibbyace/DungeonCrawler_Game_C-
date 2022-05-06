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
    virtual string getTexture();
    virtual bool hasCharacter();
    virtual bool moveTo(Tile* fromTile, Character* who); //wird von aktueller tile (this), true if move
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;//betreten einer tile (ist this) ist sie nicht beretbar Nullptr
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;//auch this;
    //Gibt this bei floor zurück, gibt nullptr bei Wall zurück, gibt zeiger auf portal bei portal zurück;
    virtual ~Tile() = default;// Default destructor bitte wie links, weil sonst komische fehler mit compiler



    void setCharacter(Character *newCharacter);
    int getRow() const;
    int getColumn() const;
};

#endif // TILE_H
