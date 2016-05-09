#pragma once
#include "abstractevent.h"
class hitPlayerEvent :
	public abstractEvent
{
public:

	hitPlayerEvent(int dmg);
	virtual eventTypeId getEventType()const override { return hitPlayerMessage; }

	int damage;
};

