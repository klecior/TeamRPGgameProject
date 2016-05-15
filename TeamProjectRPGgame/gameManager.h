#pragma once

#include"gameObject.h"
#include<vector>
#include<sstream>
#include<string>
//#include<time.h>
#include<iostream>
#include"constants.h"
#include"observer.h"
#include"messageBus.h"
//events
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include "quitGameEvent.h"
class gameManager : public observer
{
protected:

	gameManager(void);
	static gameManager*	pSharedGameManager;

	std::vector<gameObject*> allGameObjects;		//contains basically all the objects currently loaded in the game.

	float		startTime;							//used for frame limiter.
public:

	~gameManager(void);
	static gameManager*	sharedGameManager();

	//--other variables--//
	bool isRunning;
	//-------------------//

	//--stuff to do each frame--//
	void regulateFrameRate();
	void sweep();
	//--------------------------//

	void handleMessage(abstractEvent& msgEvent);

};

