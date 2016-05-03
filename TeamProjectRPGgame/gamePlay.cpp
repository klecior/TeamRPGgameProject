#include "gamePlay.h"


gamePlay::gamePlay(void)
{
	backButton = NULL;
}


gamePlay::~gamePlay(void)
{
	backButton = NULL;
}

void gamePlay::handleEvent()
{
	if(finishedLoading)
	{

		if(backButton->mouseClick())
		{ 
			messageBus::sharedMessageBus()->sendMessageS(msgEvent(setState,TITLE,false)); 
			messageBus::sharedMessageBus()->sendMessageS(msgEvent(setGUIstate,TITLE,false));
		}

	}
}

void gamePlay::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(GAME);

	}
	
}

void gamePlay::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(GAME);
		//Drawing collisions is something for rendering system
		//if (gameManager::sharedGameManager()->space)
		//{
		//	gameManager::sharedGameManager()->drawCollisionBoxes();
		//}

	}
}

void gamePlay::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		backButton = new button(GAME,"images/template/buttons/back.png","images/template/buttons/backOver.png");
		backButton->setPos('x',1000);
		backButton->setPos('y',600);

		mainPlayer = new player();

		finishedLoading = true;
	}
}