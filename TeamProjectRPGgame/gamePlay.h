#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "button.h"
#include "player.h"
#include "messageBus.h"

#include "changeStateEvent.h"

class gamePlay :
	public baseGameState
{
protected:

	void loadOnCreation();

	button* backButton;

	player*			mainPlayer;

public:
	gamePlay(void);
	~gamePlay(void);

	
	void handleEvent();
	void updateDrawing();
	void updateWorld();

	void handleMessage(int message);
};

