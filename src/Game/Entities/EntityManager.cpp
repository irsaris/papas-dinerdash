#include "EntityManager.h"

void EntityManager::tick(){
    for(int i=0; i<entities.size(); i++){
        entities[i]->tick();
    }
    if(firstClient != nullptr){
        firstClient->tick();
    }
    removeLeavingClients();
}

void EntityManager::removeLeavingClients(){
    Client* tempClient = nullptr;
    while(firstClient != nullptr && firstClient->isLeaving){
        tempClient = firstClient->nextClient;
        delete firstClient;
        firstClient = tempClient;
        clients++;
    }
    
}
void EntityManager::render(){
    for(int i=0; i<entities.size(); i++){
        entities[i]->render();
    }
    if(firstClient != nullptr){
        firstClient->render();
    }
}

void EntityManager::addEntity(Entity *e){
    entities.push_back(e);
}

void EntityManager::addClient(Client* c){
    if(firstClient == nullptr){
        firstClient = c;
    }else{
        Client* tempClient = firstClient;
        tempClient->setY(tempClient->getY()+90);
        while(tempClient->nextClient!=nullptr){
            tempClient = tempClient->nextClient;
            tempClient->setY(tempClient->getY()+90);

        }
        tempClient->nextClient = c;
    }
}

int EntityManager::getClients(){
    return clients;
}