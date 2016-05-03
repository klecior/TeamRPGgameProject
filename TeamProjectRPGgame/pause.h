#pragma once
#include "basegamestate.h"
#include "constants.h"

#include "textureImage.h"
#include "button.h"

class pause :
	public baseGameState
{
protected:

	void loadOnCreation();

	button* backButton;

public:
	pause(void);
	~pause(void);

	void handleEvent();
	void updateDrawing();
	void updateWorld();
};

