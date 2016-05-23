#pragma once
#include "abstractEvent.h"

#include"gameObject.h"
#include"statusEffect.h"


class statusEffectEndedEvent :
	public abstractEvent
{
public:
	
	virtual eventTypeId getEventType()const override { return statusEffectEndedMessage; }
};