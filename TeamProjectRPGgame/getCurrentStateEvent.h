#pragma once
#include "abstractevent.h"
class getCurrentStateEvent :
	public abstractEvent
{
public:

	virtual eventTypeId getEventType()const override {return getCurrentStateMessage;}
	
	int currentStateIs;
};

