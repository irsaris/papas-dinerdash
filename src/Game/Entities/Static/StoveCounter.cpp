#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item* item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite){
    this->item = item;

    vector<ofImage> v;
	for (int i = 0; i < 13; i++){
		if(i < 10){
            temp.load("images\\LoadingBarFrames\\frame_0" + to_string(i) + "_delay-0.3s.gif");
        }
        else{
            temp.load("images\\LoadingBarFrames\\frame_" + to_string(i) + "_delay-0.3s.gif");
        }
        
        temp.crop(10, 35, 81, 17);
		v.push_back(temp);
	}
	loadingBar = new Animation(15, v);
}

Item* StoveCounter::getItem(){

    if(!isCooking){
        isCooking = true;
        return nullptr;
    }
    else{
        if(counter >= 195){
            isCooking = false;
            counter = 0;
            return item;
        }
        return nullptr;
    }
}

void StoveCounter::tick(){
    if(isCooking && counter < 195){
        counter++;
        loadingBar->tick();
    }
    else if(isCooking && counter >= 195){
        loadingBar->setToLastFrame();
    }
    else{
        loadingBar->setToFirstFrame();
    }
}

void StoveCounter::render(){
    
    BaseCounter::render();
    if(isCooking){
        loadingBar->getCurrentFrame().draw(x, y-40, 100, 35);
    }   
}

void StoveCounter::showItem(){
    if(!isCooking){
        item->sprite.draw(x+width/2-25, y-30, 50, 30);
    }
}
