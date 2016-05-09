#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"

//events//
#include "getMousePosEvent.h"
#include "leftMouseClickEvent.h"
#include "getCurrentStateEvent.h"
#include "movePlayerEvent.h"
#include "changeHealthEvent.h"
#include "changeStateEvent.h"
#include "hitPlayerEvent.h"

//**input System class keeps track of all the inputs, both mouse and keyboard happening,					**//
//**then translates what they mean based on the current state, and send the right message based on meaning	**//
class inputSystem : public observer
{
protected:

#pragma region keys
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
#pragma endregion all of the key variables in the program


	int mouseX;
	int mouseY;

	void handleMouse(SDL_Event &evt);
	void manageKeyHolds(SDL_Event &evt);


	//event handlers//
	void getMousePosition(abstractEvent* msgEvent);
	//-------------//

	void translateMeaning();
	
	void gameplayInputs();
	void menuInputs();


public:
	inputSystem(void);
	~inputSystem(void);
	void manageInput(SDL_Event &evt);
	

	void handleMessage(abstractEvent& msgEvent);

};

