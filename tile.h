#ifndef TILE_H
#define TILE_H
#include <string>

using namespace std;

class Character;
class Tile
{
protected:
  string texture; //textur in terminalui
  Character* character = nullptr;
  const int row;
  const int column;


public:
    Tile(int row, int column);
    virtual std::string getTexture();//floor "." //if character on tile, dann x //auscoden in unteren klassen
    virtual bool hasCharacter(); //is character on tile? return true sonst immer false
    virtual bool moveTo(Tile* fromTile, Character* who); //wird von aktueller tile (this), true if move
    virtual Tile* onEnter(Tile* fromTile, Character* who) = 0;//betreten einer tile (ist this) ist sie nicht beretbar Nullptr
    virtual Tile* onLeave(Tile* destTile, Character* who) = 0;//auch this;
    //Gibt ->this bei floor zurück, gibt nullptr bei Wall an, gibt zeiger auf portal;
    virtual ~Tile() = default;// Default destructor bitte wie links, weil sonst komische fehler mit compiler


};

#endif // TILE_H
