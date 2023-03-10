#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger* burger): Entity(x, y, width, height, sprite){
    this->burger = burger;
}
Client::~Client(){
    burger->~Burger();
}
void Client::render(){
    ofSetColor(255, green, blue);
    sprite.draw(x, y, width, height);

    if(nextClient != nullptr){
        if(timer%30 == 0 && nextClient->patience > 0){
            timer = 0;
            green -= 5;
            blue -= 5;
        }
        timer++;
        nextClient->render();
    }      
    ofSetColor(255,255,255);
    burger->render();
    
}

void Client::tick(){
    patience--;
    burger->setY(y);
    if(patience == 0){
        isLeaving = true;
    }
    if(nextClient != nullptr){
        nextClient->tick();
    }
}

int Client::serve(Burger* burger){
    
    if(burger->equals(this->burger)){
        isLeaving = true;
        return 10;
    }
    if(nextClient != nullptr){
        return nextClient->serve(burger);
    }
    return 0;
}