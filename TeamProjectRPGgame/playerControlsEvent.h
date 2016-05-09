#pragma once
#include "abstractevent.h"
class playerControlsEvent :
	public abstractEvent
{
public:

	playerControlsEvent(bool isUp, bool isDown, bool isLeft, bool isRight,bool isLshift);
	virtual eventTypeId getEventType()const override {return playerControlsMessage;}
	
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;
	bool lShiftPressed;
};

