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
			messageBus::sharedMessageBus()->sendMessage(changeStateEvent(TITLE));
		}

	}
}

void gamePlay::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		
		//mainPlayer->update();

	}
	
}

void gamePlay::updateDrawing()
{
	if(finishedLoading)
	{
		//gameManager::sharedGameManager()->drawList(GAME);
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
		mainPlayer->setPos('x', 500);
		mainPlayer->setPos('y', 400);

		testS = new sceneryObject(GAME,true,"images/temp/X.png",600,600);
		testS = new sceneryObject(GAME,true,"images/temp/X.png",100,500);
		testS = new sceneryObject(GAME,true,"images/temp/X.png",300,300);
		testS = new sceneryObject(GAME,true,"images/temp/X.png",350,200);
		testS = new sceneryObject(GAME,true,"images/temp/X.png",500,250);

		finishedLoading = true;
	}
}