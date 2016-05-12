#pragma once
#include "abstractevent.h"
class quitGameEvent :
	public abstractEvent
{
public:

	virtual eventTypeId getEventType()const override { return quitGameMessage; }

};

