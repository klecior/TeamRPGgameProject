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


class renderSystem : public observer
{
protected:

	int currentState;

	std::map<int, std::vector<gameObject*>> scenesList;

	//void sortDrawOrder();

	//event handlers
	void changeState(abstractEvent* msgEvent);
	void addToRenderer(abstractEvent* msgEvent);
	void removeFromRenderer(abstractEvent* msgEvent);

public:
	renderSystem(void);
	~renderSystem(void);
	
	void handleMessage(abstractEvent& msgEvent);

	void drawScene();
};

