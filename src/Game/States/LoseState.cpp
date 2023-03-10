#include "LoseState.h"

LoseState::LoseState() {
    restartButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 50, "Start Over");

	original.load("imageOG.jpg");
	yes.load("imageYES.jpg");
	no.load("imageNO.jpg");
}
void LoseState::tick() {
	if(restartButton->wasPressed()){
		setNextState("Menu");
		setFinished(true);
	}
}
void LoseState::render() {
	restartButton->render();

	original.draw(0,0, ofGetWidth(), ofGetHeight());

	if(isYes){
		yes.draw(0,0, ofGetWidth(), ofGetHeight()); //key up
	}
	else{
		no.draw(0,0, ofGetWidth(), ofGetHeight()); //key down
	}
}

void LoseState::keyPressed(int key){
	switch(key){
		case OF_KEY_UP:
			isYes=true;
			break;
		case OF_KEY_DOWN:
			isYes=false;
			break;
		case OF_KEY_RETURN:
			if(isYes){
				setNextState("Menu");
				setFinished(true);
			}
			else{
				exit(0);
			}
	}
}

void LoseState::mousePressed(int x, int y, int button){
	restartButton->mousePressed(x, y);
}

void LoseState::keyReleased(int key){
}

void LoseState::reset(){
	setFinished(false);
	setNextState("");
}