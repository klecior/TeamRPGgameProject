#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "button.h"

#include "changeStateEvent.h"

class help :
	public baseGameState
{
protected:

		void loadOnCreation();

		button*	backButton;
		textureImage* keysHelp;

public:

	help(void);
	~help(void);

	
	void handleEvent();
	void updateDrawing();
	void updateWorld();

};

