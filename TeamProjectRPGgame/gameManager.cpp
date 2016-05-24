#include "gameManager.h"

/*shared static instance of the gameManager class
this is the real pSharedGameManager object global*/
gameManager*	gameManager::pSharedGameManager = NULL;

gameManager::gameManager(void)
{

	std::cout<<std::endl<<"gameManager created... "<<std::endl;

	isRunning = true;
	startTime = 0;

	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->registerListener(quitGameMessage,this);

}

gameManager::~gameManager(void)
{
	messageBus::sharedMessageBus()->unRegisterListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(quitGameMessage,this);
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

//sweep deletes any object that are no longer "alive" it does so at the very end of the frame in order to make sure that no deleted items get called.
void gameManager::sweep()
{
	for(int i=0; i<allGameObjects.size();i++)
	{
		
		if(allGameObjects.at(i)->getAlive() == false)	
		{
			std::cout << allGameObjects.at(i)->objectType << std::endl;
			messageBus::sharedMessageBus()->sendMessage(entityDeletedEvent(allGameObjects.at(i)->belongsToState, allGameObjects.at(i) ) );		//makes sure the object unregisters from any list it is on.
			delete allGameObjects.at(i);																										//deletes the actual object, calls it's destructor.
			allGameObjects.erase(allGameObjects.begin()+i);																						//deletes it from this list.
		}
	}
}

void gameManager::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == entityCreatedMessage)
	{
		entityCreatedEvent& newEntity = *(entityCreatedEvent*)&msgEvent; 	//cast
		allGameObjects.push_back(newEntity.createdObject);
	}
	
	if(msgType == quitGameMessage)
	{
		isRunning = false;
	}
}
