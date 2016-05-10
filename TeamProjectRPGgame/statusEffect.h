#pragma once
#include "gameObject.h"
#include "messageBus.h"

//Events
#include "hitPlayerEvent.h"


class statusEffect :
	public gameObject
{
public:
	statusEffect();
	statusEffect::statusEffect(gameObject *targetAddress);
	~statusEffect();
	int getDuration();
	int getStartTime();
	virtual void effect();

protected:
	int startTime, duration, endTime, remainingTime;
	gameObject *target;
};

