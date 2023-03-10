#include "GameState.h"

GameState::GameState() {
    this->restaurant = new Restaurant();
	this->entityManager = restaurant->getEntityManager();
	winnerscreen.load("DinerdashWinner.mp3");
	winnerscreen.setLoop(true);
	endscreen.load("DinerdashGameover.mp3");
	endscreen.setLoop(true);
}
void GameState::tick() {
	restaurant->tick();  
	if(restaurant->getMoney() == 100){
		ofSoundStopAll();
		winnerscreen.play();
		setNextState("Won");
		setFinished(true);
		restaurant->setMoney(0);
	}
	if(entityManager->getClients() == 10){
		ofSoundStopAll();
		endscreen.setVolume(.30);
		endscreen.play();
		setNextState("Lose");
		setFinished(true);
	}
}
void GameState::render() {
	restaurant->render();
}

void GameState::keyPressed(int key){
	restaurant->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
}

void GameState::keyReleased(int key){
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}