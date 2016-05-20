#pragma once

#include "basegamestate.h"
#include "constants.h"

#include "gameObject.h"
#include "textureImage.h"

#include "button.h"
#include "player.h"
//events
#include "changeStateEvent.h"

class title :
	public baseGameState
{
protected:

	void loadOnCreation();

	button*	startButton;
	button* helpButton;
	button* quitButton;
public:
	title(void);
	~title(void);

	void handleEvent();
	void updateDrawing();
	void updateWorld();

	int test;

};

