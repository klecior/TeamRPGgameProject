#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"

class inputSystem : public observer
{
protected:

	//allKeys//
	bool upKey;
	bool downKey;
	bool leftKey;
	bool rightKey;
	bool spaceKey;
	bool escKey;
	//-------//

	//tempDebugKeys//
	bool uKey;
	bool iKey;
	bool oKey;
	bool jKey;
	bool kKey;
	bool lKey;
	//-------------//

	int mouseX;
	int mouseY;
	void handleMouse(SDL_Event &evt);
	void manageKeyHolds(SDL_Event &evt);


	msgEvent currentStateE;
	void translateMeaning();
	void gameplayInputs();
	void menuInputs();

	void test();

public:
	inputSystem(void);
	~inputSystem(void);
	void manageInput(SDL_Event &evt);
	
	void handleMessage(int message);
	void handleMessage(msgEvent& msg);

};

