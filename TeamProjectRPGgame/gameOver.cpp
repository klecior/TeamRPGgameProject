#include "gameOver.h"


gameOver::gameOver(void)
{
}


gameOver::~gameOver(void)
{
}

void gameOver::handleEvent(SDL_Event& evt)
{
	if(finishedLoading)
	{

	}
}

void gameOver::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{

	}
	
}

void gameOver::updateDrawing()
{
	if(finishedLoading)
	{
		
		std::cout<<"gameOver "<<std::endl;
	}
}

void gameOver::loadOnCreation()
{
	if(finishedLoading == false)
	{

		//LOAD STUFF HERE//
		finishedLoading = true;
	}
}