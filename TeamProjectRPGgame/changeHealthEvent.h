#pragma once
#include "abstractevent.h"
class changeHealthEvent :
	public abstractEvent
{
public:

	changeHealthEvent(int nHealth);
	virtual eventTypeId getEventType()const override {return changeHealthMessage;}
	
	int newHealth;
};

