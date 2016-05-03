#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"

#include <vector>

//--all of the states--//
#include"baseGameState.h"
#include "title.h"
#include "gameplay.h"
#include "help.h"
#include "gameOver.h"
#include "pause.h"
//---------------------//


class stateHandler : public observer
{
protected:

	int currentState;
	std::vector<baseGameState*> stateHandlerVec;

public:
	stateHandler(void);
	~stateHandler(void);
	void handleMessage(int message);
	void handleMessage(msgEvent& msg);
	void updateGameState();
	void initialiseStates();

	

	gamePlay*		theGame;
	title*			theTitle;
	help*			theHelp;
	gameOver*		theGameOver;
	pause*			thePause;


};

