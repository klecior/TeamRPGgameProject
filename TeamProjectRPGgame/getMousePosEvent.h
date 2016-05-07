#pragma once
#include "abstractevent.h"
class getMousePosEvent :
	public abstractEvent
{
public:
	virtual eventTypeId getEventType()const override {return getMousePosMessage;}
	
	int mouseXis;
	int mouseYis;
};

