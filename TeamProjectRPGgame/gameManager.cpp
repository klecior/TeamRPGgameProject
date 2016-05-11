#include "gameManager.h"

/*shared static instance of the gameManager class
this is the real pSharedGameManager object global*/
gameManager*	gameManager::pSharedGameManager = NULL;

gameManager::gameManager(void)
{

	std::cout<<std::endl<<"gameManager created... "<<std::endl;

	isRunning = true;
	gameState = TITLE;
	startTime = 0;

	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage,this);

}

gameManager::~gameManager(void)
{
	messageBus::sharedMessageBus()->unRegisterListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(entityDeletedMessage,this);
}

gameManager* gameManager::sharedGameManager()
{	
	if(pSharedGameManager == NULL){pSharedGameManager = new gameManager();}
	return pSharedGameManager;
}

//--limiting of the framerate--//
void gameManager::regulateFrameRate()
{
	if(startTime - SDL_GetTicks() < 1000/FRAMERATE)
	{
		SDL_Delay((1000 / FRAMERATE) - (startTime - SDL_GetTicks()));
	}
	startTime = SDL_GetTicks();
}
//-----------------------------//
/*
//--COLLISION CHECKS--//
bool gameManager::checkCollisionWith(std::string type, SDL_Rect &collisionBox)
{
	for (int i = 0; i < gamePlayList.size(); i++)
	{
		//checks if the object is the right type//
		if (gamePlayList[i]->objectType == type)
		{
			//checks each of the targets collision boxes
			for (int j = 0; j < gamePlayList[i]->collisionBoxes.size(); j++)
			{
				//checks the collision
				if (gamePlayList[i]->collisionWith(&collisionBox, gamePlayList[i]->collisionBoxes[j]))
				{

					return true;
				}
			}

		}
	}


	return false;
}
*/

//sweep deletes any object that are no longer "alive" it does so at the very end of the frame in order to make sure that no deleted items get called.
void gameManager::sweep()
{
	for(int i=0; i<allGameObjects.size();i++)
	{
		if(allGameObjects.at(i)->getAlive() == false)	
		{
			messageBus::sharedMessageBus()->sendMessage(entityDeletedEvent(allGameObjects.at(i)->belongsToState, allGameObjects.at(i) ) );
			delete allGameObjects.at(i);
			allGameObjects.erase(allGameObjects.begin()+i);
		}
	}


}



void gameManager::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == entityCreatedMessage)
	{
		entityCreatedEvent& newEntity = *(entityCreatedEvent*)&msgEvent;

		allGameObjects.push_back(newEntity.createdObject);
	}

	if(msgType == entityDeletedMessage)
	{


	}
}



void gameManager::freeMemory()
{


}
/*
void gameManager::drawCollisionBoxes()
{

	for (int i = 0; i < gamePlayList.size(); i++)
	{
		gamePlayList.at(i)->drawCollisionBox();
	}

}
*/