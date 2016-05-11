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

class gameManager : public observer
{
protected:

	

	gameManager(void);
	static gameManager*	pSharedGameManager;

	//--lists for the objects contained in each of the game states--//
	std::vector<gameObject*> titleList;
	std::vector<gameObject*> gamePlayList;
	std::vector<gameObject*> helpList;
	std::vector<gameObject*> gameOverList;
	std::vector<gameObject*> pauseList;

	std::vector<gameObject*> allGameObjects;
	//--------------------------------------------------------------//


	float		startTime;			//used for frame limiter.

	unsigned int	gameState;		//hold the curent state of the game.

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

	//--collision--//
	//bool checkCollisionWith(std::string type, SDL_Rect &collisionBox);
	//void drawCollisionBoxes();

	//--cleanUp--//
	void freeMemory();
	//-----------//

};

