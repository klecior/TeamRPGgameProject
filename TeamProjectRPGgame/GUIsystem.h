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

class GUIsystem : public observer
{
protected:

	std::vector<gameObject*>gamePlayOverlay;
	std::vector<gameObject*>inventoryScreen;
	std::vector<gameObject*>mapScreen;

	int currentState;
	void initialise();

	void drawState();
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

