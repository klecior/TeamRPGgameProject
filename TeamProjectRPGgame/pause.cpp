#include "pause.h"


pause::pause(void)
{
	backButton = NULL;
}


pause::~pause(void)
{
	backButton = NULL;
}

void pause::handleEvent()
{
	if(finishedLoading)
	{

		if(backButton->mouseClick()){	messageBus::sharedMessageBus()->sendMessage(changeStateEvent(GAME)); }

	}
}

void pause::updateWorld()
{

	loadOnCreation();
	if(finishedLoading)
	{
		
	}
	
}

void pause::updateDrawing()
{
	if(finishedLoading)
	{
		

	}
}

void pause::loadOnCreation()
{
	if(finishedLoading == false)
	{
		//LOAD STUFF HERE//

		backButton = new button(PAUSE,"images/template/buttons/back.png","images/template/buttons/backOver.png");
		backButton->setPos('x',( SCREEN_WIDTH / 2) - ( backButton->position.w / 2 ) );
		backButton->setPos('y', 550);

		finishedLoading = true;
	}
}