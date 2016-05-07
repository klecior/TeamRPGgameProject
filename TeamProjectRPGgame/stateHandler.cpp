#include "stateHandler.h"


stateHandler::stateHandler(void)
{
	messageBus::sharedMessageBus()->registerListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->registerListener(getCurrentStateMessage,this);
	currentState = TITLE;

}


stateHandler::~stateHandler(void)
{
	delete stateHandlerList[TITLE];
	delete stateHandlerList[GAME];
	delete stateHandlerList[HELP];
	delete stateHandlerList[GAMEOVER];
	delete stateHandlerList[PAUSE];

	messageBus::sharedMessageBus()->unRegisterListener(changeStateMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(getCurrentStateMessage,this);
}

void stateHandler::initialiseStates()
{
	stateHandlerList[TITLE]			=	new title();
	stateHandlerList[GAME]			=	new gamePlay();
	stateHandlerList[HELP]			=	new help();
	stateHandlerList[GAMEOVER]		=	new gameOver();
	stateHandlerList[PAUSE]			=	new pause();
}

void stateHandler::updateGameState()
{
	stateHandlerList[currentState]->handleEvent();
	stateHandlerList[currentState]->updateWorld();
	stateHandlerList[currentState]->updateDrawing();
}


void stateHandler::handleMessage(abstractEvent& msgEvent)
{
	//get the type
	int eventType = msgEvent.getEventType();

	if(eventType == changeStateMessage)		{ changeState(&msgEvent);		}
	if(eventType == getCurrentStateMessage) { getCurrentState(&msgEvent);	}
}

#pragma region event handlers

void stateHandler::changeState(abstractEvent* msgEvent)
{
	//cast it to the right type.
	changeStateEvent& changeEvent = *(changeStateEvent*)msgEvent;

	currentState = changeEvent.changeState;
}

void stateHandler::getCurrentState(abstractEvent* msgEvent)
{
	//cast to right type.
	getCurrentStateEvent& getStateEvent	= *(getCurrentStateEvent*)msgEvent;

	getStateEvent.currentStateIs = currentState;
}


#pragma endregion //functions called when certain events are received.
