#include "renderSystem.h"

renderSystem::renderSystem()
{
	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeStateMessage,this);
	currentState	=	TITLE;
	std::cout<<"rendering system created"<<std::endl;
}

renderSystem::~renderSystem()
{
	messageBus::sharedMessageBus()->unRegisterListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(entityDeletedMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStateMessage,this);
}


void renderSystem::drawScene()
{
	//go through the entire scene.
	for(int i = 0; i < scenesList[currentState].size(); i++)
	{
		//draw every object
		scenesList[currentState].at(i)->draw();
		//std::cout<<" Rendering: "<<i;
	}
	//std::cout<<std::endl;
}


void renderSystem::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == entityCreatedMessage)	{	addToRenderer(&msgEvent);		}
	if(msgType == entityDeletedMessage)	{	removeFromRenderer(&msgEvent);	}
	if(msgType == changeStateMessage)	{	changeState(&msgEvent);			}
}

#pragma region event handlers

void renderSystem::changeState(abstractEvent* msgEvent)
{
	//cast
	changeStateEvent& stateChange = *(changeStateEvent*)msgEvent;

	currentState = stateChange.changeState;
}
void renderSystem::addToRenderer(abstractEvent* msgEvent)
{
	//cast
	entityCreatedEvent& newEntity = *(entityCreatedEvent*)msgEvent;

	scenesList[newEntity.atState].push_back(newEntity.createdObject);
}

void renderSystem::removeFromRenderer(abstractEvent* msgEvent)
{
	//cast
	entityDeletedEvent& deletedEntity = *(entityDeletedEvent*)msgEvent;
	
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

#pragma endregion 