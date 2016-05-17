#pragma once
#include "abstractEvent.h"
#include"statusEffect.h"
class addStatusEffectEvent :
	public abstractEvent
{
public:
	gameObject *characterTarget;
	statusEffect *statusToGive;

	addStatusEffectEvent(int addedStatus, gameObject *target);
	virtual eventTypeId getEventType()const override { return addStatusEffectMessage; }
};

