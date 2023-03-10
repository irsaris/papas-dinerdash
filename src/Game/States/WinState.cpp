#include "WinState.h"

WinState::WinState() {
    restartButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start Over");

	vector<ofImage> v;
	for (int i = 0; i < 9; i++){
		temp.load("images\\WinnerScreenFrames\\frame_" + to_string(i) + "_delay-0.1s.gif");
		v.push_back(temp);
	}
	menuStateBackground = new Animation(3, v);
}
void WinState::tick() {
	menuStateBackground->tick();
	if(restartButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void WinState::render() {
	restartButton->render();
	menuStateBackground->getCurrentFrame().draw(0,0, ofGetWidth(), ofGetHeight());
}

void WinState::keyPressed(int key){
	if(key == ' '){
		setNextState("Menu");
		setFinished(true);
	}
}

void WinState::mousePressed(int x, int y, int button){
    restartButton->mousePressed(x, y);
}

void WinState::keyReleased(int key){
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
}