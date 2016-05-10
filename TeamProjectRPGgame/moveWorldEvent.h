#pragma once
#include "abstractevent.h"
class moveWorldEvent :
	public abstractEvent
{
public:

	moveWorldEvent(int moveX, int moveY);
	virtual eventTypeId getEventType()const override { return moveWorldMessage; }

	int x;
	int y;
};

