#ifndef TILE_H
#define TILE_H
#include <string>
#include "character.h"



class Tile
{

  std::string texture; //textur in terminalui
  Character* character = NULL;
  const int row;
  const int column;


public:
    Tile(std::string texture, Character* character, const int row, const int column);
    virtual std::string getTexture();//floor "." //if character on tile, dann x
    virtual bool hasCharacter(); //is character on tile? return true sonst immer false
    virtual bool moveTo(Tile* fromTile, Character* who); //wird von aktueller tile (this), true if move
    virtual Tile* onEnter(Tile* fromTile, Character* who);//betreten einer tile (ist this) ist sie nicht beretbar Nullptr
    virtual Tile* onLeave(Tile* destTile, Character* who);//auch this;
    //Gibt ->this bei floor zurück, gibt nullptr bei Wall an, gibt zeiger auf portal;


};

#endif // TILE_H
