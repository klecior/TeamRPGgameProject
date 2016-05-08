#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"
#include "gameObject.h"

#include <vector>
#include <map>

//--events--//
#include "changeStateEvent.h"
#include "getCurrentStateEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"


class gameLogicSystem : public observer
{
protected:

	int currentState;

	std::map<int, std::vector<gameObject*>> scenesList;

	//event handlers
	void changeState(abstractEvent* msgEvent);
	void addToScene(abstractEvent* msgEvent);
	void removeFromScene(abstractEvent* msgEvent);

public:
	gameLogicSystem(void);
	~gameLogicSystem(void);
	
	void handleMessage(abstractEvent& msgEvent);

	void doLogic();
};

