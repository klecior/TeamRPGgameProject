#include "GUIsystem.h"

GUIsystem::GUIsystem()
{

	currentState = TITLE;
	messageBus::sharedMessageBus()->registerListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeHealthMessage,this);
	messageBus::sharedMessageBus()->registerListener(changeStaminaMessage,this);
}

GUIsystem::~GUIsystem()
{
	messageBus::sharedMessageBus()->unRegisterListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeHealthMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStaminaMessage,this);
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
	gamePlayOverlay.push_back(healthBar);
	gamePlayOverlay.push_back(staminaBar);
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

}

//draws the state//
void GUIsystem::drawState()
{

	if(currentState == GAME)
	{
		for(int i = 0; i < gamePlayOverlay.size(); i++){ gamePlayOverlay[i]->update(); }	
		for(int i = 0; i < gamePlayOverlay.size(); i++){ gamePlayOverlay[i]->draw();   }	
	}
	if(currentState == INVENTORY)
	{
		for(int i = 0; i < inventoryScreen.size(); i++){ inventoryScreen[i]->update(); }	
		for(int i = 0; i < inventoryScreen.size(); i++){ inventoryScreen[i]->draw(); }	
	}
	if(currentState == MAPSCREEN)
	{
		for(int i = 0; i < mapScreen.size(); i++){ mapScreen[i]->update(); }	
		for(int i = 0; i < mapScreen.size(); i++){ mapScreen[i]->draw(); }	
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

#pragma endregion 