#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"
#include "gameObject.h"

#include <vector>
#include <map>

#include "quadTree.h"
#include "collision.h"

//--events--//
#include "changeStateEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"

class collisionSystem : public observer
{
protected:

	int currentState;

	quadTree*	quad;

	//std::map<int, std::vector<gameObject*>> scenesList;

	std::vector<gameObject*> collideableObjectList;

	//event handlers
	void changeState(abstractEvent* msgEvent);
	void addToList(abstractEvent* msgEvent);
	void removeFromList(abstractEvent* msgEvent);

public:
	collisionSystem(void);
	~collisionSystem(void);
	
	void handleMessage(abstractEvent& msgEvent);

	void checkCollisions();
};

