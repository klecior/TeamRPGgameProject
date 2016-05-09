#include "GUIsystem.h"

GUIsystem::GUIsystem()
{

	currentState = TITLE;
	messageBus::sharedMessageBus()->registerListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeHealthMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeStaminaMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage, this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage, this);
}

GUIsystem::~GUIsystem()
{
	messageBus::sharedMessageBus()->unRegisterListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeHealthMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStaminaMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(entityCreatedMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(entityDeletedMessage, this);
}

void GUIsystem::initialise()
{
	std::cout<<"initialising GUI"<<std::endl;

	//--INITIALISE GAME OVERLAY--//
	healthBar = new GUIbar(100,"Assets/GUI/healthBar/backdrop.png","Assets/GUI/healthBar/bar.png","Assets/GUI/healthBar/border.png");
	healthBar->setPos('x',100);
	healthBar->setPos('y',600);
	healthBar->updatePercentage(100);

	staminaBar = new GUIbar(100,"Assets/GUI/healthBar/backdrop.png","Assets/GUI/healthBar/bar.png","Assets/GUI/healthBar/border.png");
	staminaBar->setPos('x',800);
	staminaBar->setPos('y',600);
	//gamePlayOverlay.push_back(healthBar);
	//gamePlayOverlay.push_back(staminaBar);
	//GUIstatesList[GAME].push_back(healthBar);
	//GUIstatesList[GAME].push_back(staminaBar);
	//---------------------------//

	//--INITIALISE INVENTORY--//
	
	//------------------------//

	//--INITIALISE MAP--//

	//------------------//
}

void GUIsystem::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == changeStateMessage)	{ changeState(&msgEvent);			}
	if(msgType == changeHealthMessage)	{ updateHealthBar(&msgEvent);		}
	if(msgType == changeStaminaMessage) { updateStaminaBar(&msgEvent);		}
	if(msgType == entityCreatedMessage) { addGUIobject(&msgEvent);			}	
	if(msgType == entityDeletedMessage) { removeGUIobject(&msgEvent);		}

}

//draws the state//
void GUIsystem::drawState()
{
	for (int i = 0; i < GUIstatesList[currentState].size(); i++) 
	{ 
		GUIstatesList[currentState].at(i)->update();
		GUIstatesList[currentState].at(i)->draw();
	}

}

#pragma region event handlers

void GUIsystem::changeState(abstractEvent* msgEvent)
{
	//cast
	changeStateEvent& stateChange = *(changeStateEvent*)msgEvent;

	currentState = stateChange.changeState;
}

void GUIsystem::updateHealthBar(abstractEvent* msgEvent)
{
	//cast
	changeHealthEvent& healthChange = *(changeHealthEvent*)msgEvent;

	healthBar->updatePercentage(healthChange.newHealth);
}

void GUIsystem::updateStaminaBar(abstractEvent* msgEvent)
{
	//cast
	changeStaminaEvent& staminaChange = *(changeStaminaEvent*)msgEvent;

	staminaBar->updatePercentage(staminaChange.newStamina);
}

void GUIsystem::addGUIobject(abstractEvent* msgEvent)
{
	//cast
	entityCreatedEvent& newEntity = *(entityCreatedEvent*)msgEvent;

	std::cout << "dadsadsa";

	//if the object created was a GUI object
	if (newEntity.type == "GUI")
	{

		std::cout << newEntity.type << " " << newEntity.atState << std::endl;

		GUIstatesList[newEntity.atState].push_back(newEntity.createdObject);
		std::cout << "adding something to GUI" << std::endl;
	}
}

void GUIsystem::removeGUIobject(abstractEvent* msgEvent)
{
	//cast
	entityDeletedEvent& newEntity = *(entityDeletedEvent*)msgEvent;
	
	//go through that state list
	for (int i = 0; i < GUIstatesList[newEntity.atState].size(); i++)
	{	
		//if found the same address
		if (GUIstatesList[newEntity.atState].at(i) == newEntity.deletedObject)
		{
			//delete it from the list
			GUIstatesList[newEntity.atState].erase(GUIstatesList[newEntity.atState].begin() + 1);
		}
	}
}

#pragma endregion 