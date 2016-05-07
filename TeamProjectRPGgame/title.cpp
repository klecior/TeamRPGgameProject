#include "title.h"


title::title(void)
{
	startButton	=	NULL;
	helpButton	=	NULL;
	quitButton	=	NULL;
}


title::~title(void)
{
	startButton	=	NULL;
	helpButton	=	NULL;
	quitButton	=	NULL;
}

void title::handleEvent()
{
	if(finishedLoading)
	{

		//--buttons--//
		if(startButton->mouseClick())
		{ 
			messageBus::sharedMessageBus()->sendMessage(changeStateEvent(GAME));
		}
		if(helpButton->mouseClick()) { messageBus::sharedMessageBus()->sendMessage(changeStateEvent(HELP)); }
		if(quitButton->mouseClick()) { gameManager::sharedGameManager()->isRunning = false;	}
		//----------//

	}
}

void title::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(TITLE);
	}
	
}

void title::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(TITLE);
		//std::cout<<"title "<<std::endl;

	}
}

void title::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		startButton	 = new button(TITLE,"images/template/buttons/start.png","images/template/buttons/startOver.png");
		helpButton	 = new button(TITLE,"images/template/buttons/help.png","images/template/buttons/helpOver.png");
		quitButton	 = new button(TITLE,"images/template/buttons/quit.png","images/template/buttons/quitOver.png");

		startButton->setPos('x', (SCREEN_WIDTH / 2 ) - (startButton->getPosition().w / 2) );
		helpButton->setPos('x', (SCREEN_WIDTH / 2 ) - (helpButton->getPosition().w / 2) );
		quitButton->setPos('x', (SCREEN_WIDTH / 2 ) - (quitButton->getPosition().w / 2) );

		startButton->setPos('y', 150 );
		helpButton->setPos('y', 350 );
		quitButton->setPos('y', 550 );

		finishedLoading = true;
	}
}