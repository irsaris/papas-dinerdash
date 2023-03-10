#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {

public:
	Client* firstClient;
	int clients = 0;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	int getClients();
	std::vector<Entity*> entities;

};