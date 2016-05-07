#pragma once
#include "abstractevent.h"
class changeStateEvent :
	public abstractEvent
{
public:

	changeStateEvent(int newState);
	virtual eventTypeId getEventType()const override {return changeStateMessage;}
	
	int changeState;
};

