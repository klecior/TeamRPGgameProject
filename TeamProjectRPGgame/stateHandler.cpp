#include "stateHandler.h"


stateHandler::stateHandler(void)
{
	messageBus::sharedMessageBus()->registerSystem(this);
	currentState = TITLE;

}


stateHandler::~stateHandler(void)
{
	delete theTitle;
	delete theGameOver;
	delete theHelp;
	delete theGame;
	delete thePause;

	theTitle	= NULL;
	theGameOver = NULL;
	theHelp		= NULL;
	theGame		= NULL;
	thePause	= NULL;
}

void stateHandler::initialiseStates()
{
	stateHandlerVec.push_back(theTitle		= new title()		);
	stateHandlerVec.push_back(theGame		= new gamePlay()	);
	stateHandlerVec.push_back(theHelp		= new help()		);
	stateHandlerVec.push_back(theGameOver	= new gameOver()	);
	stateHandlerVec.push_back(thePause		= new pause()		);
}

void stateHandler::updateGameState()
{
	stateHandlerVec[currentState]->handleEvent();
	stateHandlerVec[currentState]->updateWorld();
	stateHandlerVec[currentState]->updateDrawing();
}


void stateHandler::handleMessage(int message)
{

}

void stateHandler::handleMessage(msgEvent &msg)
{
	if(msg.eventID == setState)				{		currentState	=	msg.intData;	}
	if(msg.eventID == getCurrentGameState)	{		msg.intData		=	currentState;	}
}