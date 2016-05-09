#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"
#include <vector>
#include "gameObject.h"
#include <map>

//gui objects//
#include "GUIbar.h"
//-----------//

//events//
#include "changeHealthEvent.h"
#include "changeStaminaEvent.h"
#include "changeStateEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
//------//


//**GUI System class is responsible for loading, storing, and updating all of the GUI related elements. It's servers as a way for object's to update the GUI, without having to be coupled with it**//
class GUIsystem : public observer
{
protected:

	//lists for all of the diffrent GUI states/settings.
	//std::vector<gameObject*>gamePlayOverlay;
	//std::vector<gameObject*>inventoryScreen;
	//std::vector<gameObject*>mapScreen;

	std::map<int, std::vector<gameObject*>> GUIstatesList;

	//TODO change the vectors into a single map implementation for easier usage.

	int currentState;

	//gameOverlay
	GUIbar*		healthBar;
	GUIbar*		staminaBar;

	//event handlers
	void updateHealthBar(abstractEvent* msgEvent);
	void updateStaminaBar(abstractEvent* msgEvent);
	void changeState(abstractEvent* msgEvent);

	void addGUIobject(abstractEvent* msgEvent);
	void removeGUIobject(abstractEvent* msgEvent);

public:
	GUIsystem(void);
	~GUIsystem(void);
	
	void initialise();
	void drawState();			//draw the GUI, whatever it may currently be.

	void handleMessage(abstractEvent& msgEvent);

};

