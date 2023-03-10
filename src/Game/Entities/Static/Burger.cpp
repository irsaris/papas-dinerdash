//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

bool Burger::equals(Burger *b){
    
    stack<Item*> ingCopy(this->ingredients);
    stack<Item*> ing(b->ingredients);

    int tomato=0, tomato2=0, cheese=0, cheese2=0, patty=0, patty2=0, ketchup=0, ketchup2=0, lettuce=0, lettuce2=0;
    while(!ingCopy.empty()){
        Item* ingredient = ingCopy.top();
        if(ingredient->name.compare("tomato") == 0){
            tomato++;
        } 
        else if(ingredient->name.compare("cheese") == 0){
            cheese++;
        } 
        else if(ingredient->name.compare("ketchup") == 0){
            ketchup++;
        } 
        else if(ingredient->name.compare("lettuce") == 0){
            lettuce++;
        } 
        else if(ingredient->name.compare("patty") == 0){
            patty++;
        } 
        ingCopy.pop();
    }

    while(!ing.empty()){
        Item* ingredient = ing.top();
        if(ingredient->name.compare("tomato") == 0){
            tomato2++;
        } 
        else if(ingredient->name.compare("cheese") == 0){
            cheese2++;
        } 
        else if(ingredient->name.compare("ketchup") == 0){
            ketchup2++;
        } 
        else if(ingredient->name.compare("lettuce") == 0){
            lettuce2++;
        } 
        else if(ingredient->name.compare("patty") == 0){
            patty2++;
        } 
        ing.pop();
    }

    return tomato == tomato2 && cheese == cheese2 && ketchup == ketchup2 && lettuce == lettuce2 && patty == patty2;
}

void Burger::addIngredient(Item *item) {
    ingredients.push(item);
}

void Burger::render(){
    stack<Item*> temp;
    int counter = -2;
    int size = this->ingredients.size();

    for(int i = 0; i < size; i++){
        Item* ingredient = this->ingredients.top();
        this->ingredients.pop();
        temp.push(ingredient);
    }
    for(int j = 0; j < size; j++){
        Item* ingredient = temp.top();
        ingredient->sprite.draw(x,y-(counter * 10),width,height);
        counter++;
        this->ingredients.push(ingredient);
        temp.pop();
    }
}

void Burger::clear(){
    int size = this->ingredients.size();
    for(int i = 0; i < size; i++){
        this->ingredients.pop();
    }
}

void Burger::undo(){
    if(!this->ingredients.empty()){
        this->ingredients.pop();
    }
}