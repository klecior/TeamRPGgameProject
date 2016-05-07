#pragma once
#include "abstractevent.h"
class movePlayerEvent :
	public abstractEvent
{
public:

	movePlayerEvent(bool isUp, bool isDown, bool isLeft, bool isRight);
	virtual eventTypeId getEventType()const override {return movePlayerMessage;}
	
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
};

