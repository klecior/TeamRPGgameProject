#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"
#include <vector>
#include "gameObject.h"

//gui objects//
#include "GUIbar.h"

//-----------//

//**GUI System class is responsible for loading, storing, and updating all of the GUI related elements. It's servers as a way for object's to update the GUI, without having to be coupled with it**//
class GUIsystem : public observer
{
protected:

	//lists for all of the diffrent GUI states/settings.
	std::vector<gameObject*>gamePlayOverlay;
	std::vector<gameObject*>inventoryScreen;
	std::vector<gameObject*>mapScreen;

	int currentState;
	void initialise();

	void drawState();			//draw the GUI, whatever it may currently be.
	void updateState();

	//gameOverlay
	GUIbar*		healthBar;
	GUIbar*		staminaBar;

public:
	GUIsystem(void);
	~GUIsystem(void);
	
	void handleMessage(int message);
	void handleMessage(msgEvent& msg);


};

