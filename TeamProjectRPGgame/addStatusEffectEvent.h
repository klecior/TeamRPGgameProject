#pragma once
#include "abstractEvent.h"
#include"statusEffect.h"
class addStatusEffectEvent :
	public abstractEvent
{
public:
	//statusEffect *statusToGive;
	int statusToGive;
	gameObject* targetCharacter;

	addStatusEffectEvent(int addedStatus, gameObject *target);
	virtual eventTypeId getEventType()const override { return addStatusEffectMessage; }
};

