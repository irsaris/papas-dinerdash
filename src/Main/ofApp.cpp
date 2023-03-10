#include "ofApp.h"
#include "Images.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Papa's Diner Dash");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	loseState = new LoseState();
	winState = new WinState();
	// Initial State
	currentState = menuState; 

	ofSoundStopAll();
	currentState->background.load("PapasPizzeriaTitle.mp3");
	currentState->background.setLoop(true);
	currentState->background.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}else if(currentState->getNextState() == "Game"){
				currentState = gameState;
			}
			else if(currentState->getNextState() == "Lose"){
				currentState = loseState;
			}
			else if(currentState->getNextState() == "Won"){
				currentState = winState;
			}
			currentState->reset(); 
		}
	}
	if(loseState->hasFinished()){
	setup();
	}
	if(winState->hasFinished()){
	setup();
	}

	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr){
		currentState->render();
	}
	if(currentState == winState){
		string space = "Press SPACE to restart";
		ofDrawBitmapString(space, ofGetWidth()/2-space.length()*4, ofGetHeight()*.9);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
