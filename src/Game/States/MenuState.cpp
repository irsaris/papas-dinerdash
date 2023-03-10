#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(272, 45, 277, 184, " ");
	start.load("StartPressSound.mp3");

	vector<ofImage> v;
	for (int i = 0; i < 38; i++){
		if (i < 10){
			temp.load("images\\MenuScreenFrames\\frame_0" + to_string(i) + "_delay-0.1s.gif");
		}
		else{
			temp.load("images\\MenuScreenFrames\\frame_" + to_string(i) + "_delay-0.1s.gif");	
		}
		v.push_back(temp);
	}
	
	menuStateBackground = new Animation(3, v);
}
void MenuState::tick() {
	startButton->tick();
	menuStateBackground->tick();

	if(startButton->wasPressed()){
		start.play();
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render() {

	startButton->render();
	menuStateBackground->getCurrentFrame().draw(0,0, ofGetWidth(), ofGetHeight());
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}