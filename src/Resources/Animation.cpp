#include "Animation.h"

Animation::Animation(int speed, std::vector<ofImage> frames){
    this->speed = speed;
    this->frames = frames;
    this->index = 0;
    this->timer = 0;
}

void Animation::tick(){
    timer += 1;
    if(timer > speed){
        index++;
        timer = 0;
        if(index == frames.size()){
            index = 0;
        }
    }
}

ofImage Animation::getCurrentFrame(){
    return frames[index];
}

void Animation::setToLastFrame(){
    index = frames.size()-1;
    timer = 0;
}

void Animation::setToFirstFrame(){
    index = 0;
    timer = 0;
}