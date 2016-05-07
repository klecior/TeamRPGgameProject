#pragma once
#include "abstractevent.h"
class changeStaminaEvent :
	public abstractEvent
{
public:

	changeStaminaEvent(int nStamina);
	virtual eventTypeId getEventType()const override {return changeStaminaMessage;}
	
	int newStamina;
};

