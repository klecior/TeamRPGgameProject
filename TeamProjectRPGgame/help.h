#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "button.h"

class help :
	public baseGameState
{
protected:

		void loadOnCreation();

		button*	backButton;

public:

	help(void);
	~help(void);

	
	void handleEvent();
	void updateDrawing();
	void updateWorld();

};

