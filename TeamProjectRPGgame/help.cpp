#include "help.h"


help::help(void)
{
	backButton = NULL;
}


help::~help(void)
{
	backButton = NULL;
}

void help::handleEvent()
{
	if(finishedLoading)
	{

		if(backButton->mouseClick()){ messageBus::sharedMessageBus()->sendMessageS(msgEvent(setState,TITLE,false)); }

	}
}

void help::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->updateList(HELP);
	}
	
}

void help::updateDrawing()
{
	if(finishedLoading)
	{
		gameManager::sharedGameManager()->drawList(HELP);

	}
}

void help::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		backButton = new button(HELP,"images/template/buttons/back.png","images/template/buttons/backOver.png");
		backButton->setPos('x',( SCREEN_WIDTH / 2) - ( backButton->getPosition().w / 2 ) +300 );
		backButton->setPos('y', 550);

		finishedLoading = true;
	}
}