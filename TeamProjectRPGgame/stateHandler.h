#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"

#include <vector>
#include <map>

//--all of the states--//
#include"baseGameState.h"
#include "title.h"
#include "gameplay.h"
#include "help.h"
#include "gameOver.h"
#include "pause.h"
//---------------------//

//--events--//
#include "changeStateEvent.h"
#include "getCurrentStateEvent.h"


class stateHandler : public observer
{
protected:

	int currentState;

	void changeState(abstractEvent* msgEvent);
	void getCurrentState(abstractEvent* msgEvent);

	std::map<int,baseGameState*> stateHandlerList;


public:
	stateHandler(void);
	~stateHandler(void);
	
	void handleMessage(abstractEvent& msgEvent);

	void updateGameState();
	void initialiseStates();


};

