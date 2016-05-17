
#pragma once
#include "abstractEvent.h"
#include <iostream>

class consumePotionEvent : public abstractEvent
{
public:
	consumePotionEvent(int potion);
	int potionName;

	virtual eventTypeId getEventType()const override { return consumePotionMessage; }

};