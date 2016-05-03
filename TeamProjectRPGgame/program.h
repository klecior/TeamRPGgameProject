#pragma once

#include<SDL.h>
#include<vector>
#include<iostream>

#include"constants.h"
#include"gameManager.h"
#include"SDLManager.h"

//--systems--//
#include "inputSystem.h"
#include "stateHandler.h"
#include "GUIsystem.h"

//**Main class for the game, contains all of the states as well as the game loop**//
class program
{
protected:

	inputSystem		inputsS;
	stateHandler	gameStatesS;
	GUIsystem		GUIs;
public:
	program(void);
	~program(void);

	//--SDL2--//
	SDL_Window*		mainWindow;
	SDL_Event		evt;
	//--------//

	bool initialise();
	void gameLoop();
	void close();

};

