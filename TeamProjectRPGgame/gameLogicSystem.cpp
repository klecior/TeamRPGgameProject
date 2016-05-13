#include "gameLogicSystem.h"

gameLogicSystem::gameLogicSystem()
{
	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeStateMessage,this);
	currentState	=	TITLE;
	collisionS = new collisionSystem();
	std::cout<<"Game logic system created"<<std::endl;
}

gameLogicSystem::~gameLogicSystem()
{
	messageBus::sharedMessageBus()->unRegisterListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStateMessage,this);
}

void gameLogicSystem::doLogic()
{
	for(int i = 0; i < scenesList[currentState].size(); i++)
	{
		//update every object
		scenesList[currentState].at(i)->update();
		//check Collisions
		collisionS->checkCollisions();
	}
}

void gameLogicSystem::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == entityCreatedMessage)	{	addToScene(&msgEvent);		}
	if(msgType == entityDeletedMessage)	{	removeFromScene(&msgEvent);	}
	if(msgType == changeStateMessage)	{	changeState(&msgEvent);			}
}


#pragma region event handlers

void gameLogicSystem::changeState(abstractEvent* msgEvent)
{
	//cast
	changeStateEvent& stateChange = *(changeStateEvent*)msgEvent;

	currentState = stateChange.changeState;
}
void gameLogicSystem::addToScene(abstractEvent* msgEvent)
{
	//cast
	entityCreatedEvent& newEntity = *(entityCreatedEvent*)msgEvent;

	if (newEntity.type != "GUI")
	{
		scenesList[newEntity.atState].push_back(newEntity.createdObject);
	}
}

void gameLogicSystem::removeFromScene(abstractEvent* msgEvent)
{
	//cast
	entityDeletedEvent& deletedEntity = *(entityDeletedEvent*)msgEvent;
	//if not something that would not be on this list.
	if(deletedEntity.deletedObject->objectType != "GUI")
	{
		//go through the scene looking for object.
		for(int i = 0; i < scenesList[deletedEntity.atState].size(); i++)
		{
			//if the address is the one of the deleted object
			if(scenesList[deletedEntity.atState].at(i) == deletedEntity.deletedObject)
			{
				//remove the object
				scenesList[deletedEntity.atState].erase(scenesList[deletedEntity.atState].begin()+i);
			}
		}
	}
}

#pragma endregion 