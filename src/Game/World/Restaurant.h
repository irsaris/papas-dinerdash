//
// Created by joshu on 11/3/2020.
//

#ifndef APGAMEENGINE_RESTAURANT_H
#define APGAMEENGINE_RESTAURANT_H
#include "ofMain.h"
#include "Player.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
#include "Inspector.h"

class Restaurant {
    private:
        Player* player;
        EntityManager* entityManager;
        int ticks=0, counter=0;
        std::vector<ofImage> people;
        int money =0;

    public:
        Restaurant();
        Player* getPlayer();
        EntityManager* getEntityManager();
        void setPlayer(Player *player);
        Item* cheese;
        Item* lettuce;
        Item* tomato;
        Item* burger;
        Item* botBread;
        Item* topBread;
        Item* ketchup;
        ofImage floor, furniture, chand, carpet, tableAndChairs, box, moneyBox, ins;

        void initItems();
        void initCounters();
        void initClients();
        void generateClient();
        void serveClient();
        void tick();
        void render();
        void keyPressed(int key);
        void setMoney(int a);
        int getMoney();
};


#endif //APGAMEENGINE_RESTAURANT_H
