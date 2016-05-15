#include "program.h"


program::program(void)
{

	mainWindow		=	NULL;

}


program::~program(void)
{
}


bool program::initialise()
{

	messageBus::sharedMessageBus()->sendMessage(changeStateEvent(TITLE));				//make sure that the starting game state is title.
	bool success = true;	//success flag

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout<<"failed to initialise, SDL Error: "<<SDL_GetError()<<std::endl;
		success = false;
	}
	else
	{
		//create main window.
		mainWindow = SDL_CreateWindow("Lets kill hitler game",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if(mainWindow == NULL)
		{
			std::cout<<"window could not be created: "<<SDL_GetError()<<std::endl;
			success = false;
		}
		else
		{
			//create main renderer.
			SDLManager::sharedSDLManager()->mainRenderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED);
	
			if(SDLManager::sharedSDLManager()->mainRenderer == NULL)
			{
				std::cout<<"renderer could not be created: "<<SDL_GetError()<<std::endl;
				success = false;
			}
			else
			{
				//set color to white
				SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xFF,0xFF,0xFF,0xFF);
				gameStatesS.initialiseStates();
				GUIs.initialise();
			}
		}
	}
	return success;
}

void program::gameLoop()
{
	while(gameManager::sharedGameManager()->isRunning == true)
	{
		//--reset the window--//
		SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xFF,0xBB,0xFF,0xFF);
		SDL_RenderClear(SDLManager::sharedSDLManager()->mainRenderer);
		//--------------------//

		//callSystems//
		inputsS.manageInput(evt);
		gameStatesS.updateGameState();
		gameLogicS.doLogic();
		//ai update?
		//Audio.play();
		renderS.drawScene();
		GUIs.drawState();

		//--Draw current screen, same function as previously SDL_Flip()--//
		SDL_RenderPresent(SDLManager::sharedSDLManager()->mainRenderer);
		
		gameManager::sharedGameManager()->regulateFrameRate();
		gameManager::sharedGameManager()->sweep();

	}
}

void program::close()
{

	SDL_DestroyWindow(mainWindow);
	mainWindow		=	NULL;

	SDL_DestroyRenderer(SDLManager::sharedSDLManager()->mainRenderer);
	SDLManager::sharedSDLManager()->mainRenderer	=	NULL;

}