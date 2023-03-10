#include "Inspector.h"

Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger* burger): Client( x, y, width, height, sprite, burger){
    this->burger = burger;
    Client::patience = 1550;
}

Inspector::~Inspector(){
    burger->~Burger();
}

void Inspector::tick(){
    if(!isLeaving){
        patience--;
    }
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}
