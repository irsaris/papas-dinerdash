#pragma once
#include "Entity.h"
#include "Burger.h"

class Client: public Entity{
    
    public:
        Client(int, int, int, int, ofImage, Burger*);
        ~Client();
        virtual void tick();
        void render();
        int serve(Burger*);
        Client* nextClient=nullptr;
        bool isLeaving=false;
        int timer = 0, green = 255, blue = 255;
        int patience = 2000;
        Burger* burger;
        int originalPatience;
};