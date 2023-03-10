#pragma once 
#include "Client.h"
// #include "Restaurant.h"

class Inspector: public Client{

    public:
        Inspector(int, int, int, int, ofImage, Burger*);
        ~Inspector();
        virtual void tick();
        bool tookMoney = false;
};