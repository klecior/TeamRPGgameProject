#include "GUIsystem.h"

GUIsystem::GUIsystem()
{

	currentState = TITLE;
	messageBus::sharedMessageBus()->registerSystem(this);
}

GUIsystem::~GUIsystem()
{

}

void GUIsystem::initialise()
{
	std::cout<<"initialising GUI"<<std::endl;
	//--INITIALISE GAME OVERLAY--//
	healthBar = new GUIbar(100,"Assets/GUI/healthBar/backdrop.png","Assets/GUI/healthBar/bar.png","Assets/GUI/healthBar/border.png");
	healthBar->setPos('x',100);
	healthBar->setPos('y',600);
	healthBar->updatePercentage(50);

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

void GUIsystem::handleMessage(int message)
{
	if(message == initialiseGUI){ initialise(); }
	if(message == drawGUI)		{ drawState();	}
}
void GUIsystem::handleMessage(msgEvent& msg)
{
	
	if(msg.eventID == setGUIstate)	{	currentState = msg.intData;					}
	if(msg.eventID == drawGUI)		{	drawState();								}
	if(msg.eventID == initialiseGUI){	initialise();								}
	if(msg.eventID == healthChange) {   healthBar->updatePercentage(msg.intData); std::cout<<"asdsad";	}
	if(msg.eventID == staminaChange){   staminaBar->updatePercentage(msg.intData);	}
}

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