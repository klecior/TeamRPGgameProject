#include "gamePlay.h"
#include <random>;

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
		
		for(int i = 0; i < 100; i++)
		{
			testS = new sceneryObject(GAME,true,"images/temp/X.png",rand()%SCREEN_WIDTH,rand()%SCREEN_HEIGHT);
		}
		
		int xP = 0;
		int yP = 0;
		/*for(int i = 0; i < 50; i++)
		{
			testS = new sceneryObject(GAME,true,"images/temp/X.png",xP,yP);

			xP += 66;

			if(xP >= SCREEN_WIDTH - 100)
			{
				xP = 0;
				yP += 66;
			}
		}*/

		//testS = new sceneryObject(GAME,true,"images/temp/X.png",600,600);
		//testS = new sceneryObject(GAME,true,"images/temp/X.png",100,500);
		//testS = new sceneryObject(GAME,true,"images/temp/X.png",300,300);
		//testS = new sceneryObject(GAME,true,"images/temp/X.png",400,200);
		//testS = new sceneryObject(GAME,true,"images/temp/X.png",800,300);

		finishedLoading = true;
	}
}