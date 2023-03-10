//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"

Player *Restaurant::getPlayer() {
    return player;
}

EntityManager *Restaurant::getEntityManager() {
    return entityManager;
}

void Restaurant::setPlayer(Player *player) {
    this->player = player;
} 
Restaurant::Restaurant() {
    floor.load("images/floor.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    chefPlayerImage.load("images/chef.png");
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);    
    initItems();
    initCounters();
    initClients();
    generateClient();

    furniture.load("images/sprite.png");
    tableAndChairs.cropFrom(furniture, 20, 12, 122, 77);
    box.load("images/moneyBox.png");
    moneyBox.cropFrom(box, 86, 34, 297, 118);
    carpet.load("images/Welcome.png");
    chand.load("images/chandelier.png");
}
void Restaurant::initItems(){
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg, ketchupImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43); // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48); // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39); // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41); // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34); // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51); // plate
    ketchupImg.cropFrom(burgerSpriteSheet, 164, 16, 119, 45); // ketchup

    cheese = new Item(cheeseImg, "cheese"); 
    lettuce = new Item(lettuceImg, "lettuce");
    tomato = new Item(tomatoImg, "tomato");
    burger = new Item(burgerImg, "patty");
    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
    ketchup = new Item(ketchupImg, "ketchup");
}
void Restaurant::initCounters(){
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, ketchupCounterImg, stoveCounterImg, lettuceCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet,224,12,32,43);//stoveTop
    lettuceCounterImg.cropFrom(counterSheet,96,76,32,43);//Vegetables
    tomatoCounterImg.cropFrom(counterSheet,96,200,32,48);//fruit basket
    cheeseCounterImg.cropFrom(counterSheet,64,73,32,46);//cheese
    plateCounterImg.cropFrom(counterSheet,0,133,32,50);//plates
    breadCounterImg.cropFrom(counterSheet,0,63,34,56);//buns
    ketchupCounterImg.cropFrom(counterSheet, 128, 129, 32, 55);//ketchup
    entityManager->addEntity(new BaseCounter(0,yOffset-16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth, yOffset-7, counterWidth, 108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth*2, yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*5, yOffset-10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*6, yOffset-32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*7, yOffset-32, counterWidth, 133, topBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth*4, yOffset-27, counterWidth, 133, ketchup, ketchupCounterImg));
}
void Restaurant::initClients(){
    ofImage temp;
    temp.load("images/People/Car_Designer3Female.png");
    people.push_back(temp);
    temp.load("images/People/Freedom_Fighter2Male.png");
    people.push_back(temp);
    temp.load("images/People/Hipster.png");
    people.push_back(temp);
    temp.load("images/People/Lawyer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Mad_Scientist3Female.png");
    people.push_back(temp);
    temp.load("images/People/Programmer2Male.png");
    people.push_back(temp);
    temp.load("images/People/Songwriter3Male.png");
    people.push_back(temp);
    temp.load("images/People/Weather_Reporter2Female.png");
    people.push_back(temp);
    ins.load("images/People/GordonRamsay.png");
    
}
void Restaurant::tick() {
    ticks++;
    if(ticks % 400 == 0){
        counter++;
        generateClient();
    }
    player->tick();
    entityManager->tick();

    Client* c = entityManager->firstClient;
    while(c != nullptr){

        Inspector* ins = dynamic_cast<Inspector*>(c);
        if(ins != NULL && ins->patience == 0 && !ins->tookMoney){
            ins->tookMoney = true;
            setMoney(getMoney()/2);
        }
        c = c->nextClient;
    }
}
void Restaurant::generateClient(){
    Burger* b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);

    int size = int(ofRandom(3,6));
    for(int i = 0; i < size; i++){
        switch(int(ofRandom(5))){
            case 0:
                b->addIngredient(burger);
                break;
            case 1:
                b->addIngredient(cheese);
                break;
            case 2:
                b->addIngredient(tomato);
                break;
            case 3:
                b->addIngredient(lettuce);
                break;
            case 4:
                b->addIngredient(ketchup);
                break;
        }
    }
    b->addIngredient(topBread);

    if(counter==5){ 
        counter = 0;
        entityManager->addClient(new Inspector(-12, 50, 100, 90, ins, b));
    }
    else{
        entityManager->addClient(new Client(0, 50, 64, 72, people[ofRandom(8)], b));
    }  
}
void Restaurant::render() {
    floor.draw(0,0, ofGetWidth(), ofGetHeight());
    chand.draw(ofGetWidth()/2, ofGetHeight()*.001, 120, 140);
    carpet.draw(ofGetWidth()/30, ofGetHeight()*.1, 50, 70);
    tableAndChairs.draw(ofGetWidth()/2.2, ofGetHeight()*.4, 180, 140);
    tableAndChairs.draw(ofGetWidth()/4, ofGetHeight()*.2, 180, 140);
    tableAndChairs.draw(ofGetWidth()*.7, ofGetHeight()*.2, 180, 140);
    moneyBox.draw(ofGetWidth()/30, ofGetHeight()*.89, 125, 60);

    player->render();
    entityManager->render();
    ofSetColor(256, 256, 256);
    ofDrawBitmapString("MONEY: " + to_string(money), ofGetWidth()/15, ofGetHeight()*.93);
}
void Restaurant::serveClient(){
    if(entityManager->firstClient!= nullptr){
        int temp = entityManager->firstClient->serve(player->getBurger());
        if(temp > 0){
            money += temp;
            this->player->getBurger()->clear();
        }
    }
}
void Restaurant::keyPressed(int key) {
    player->keyPressed(key);
    if(key == 's'){
        serveClient();
    }
    if(key == 'm'){
        money=money+5;
    }
}
void Restaurant::setMoney(int a) {
    money = a;
}
int Restaurant::getMoney() {
    return money; 
}


