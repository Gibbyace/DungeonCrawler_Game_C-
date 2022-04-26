#include "character.h"
#include <string>




Character::Character()
{

}

int Character::move(){

    int input;

    std::cout<<"Where do you want to go?"<<"\n";
    std::cout<<"1: Down-Right"<<"\n";
    std::cout<<"2: Down"<<"\n";
    std::cout<<"3: Down-Right"<<"\n";
    std::cout<<"4: Left"<<"\n";
    std::cout<<"5: Stay"<<"\n";
    std::cout<<"6: Right"<<"\n";
    std::cout<<"7: Left-Up"<<"\n";
    std::cout<<"8: Up"<<"\n";
    std::cout<<"9: Up-Right"<<"\n";
    std::cout<<"0: Close Game"<<"\n";

    std::cin>>input;

    switch(input){
    case 1: return 1; break;
    case 2: return 2; break;
    case 3: return 3; break;
    case 4: return 4; break;
    case 5: return 5; break;
    case 6: return 6; break;
    case 7: return 7; break;
    case 8: return 8; break;
    case 9: return 9; break;
    case 0: return 0; break;
    default: return 5;
    }
}
