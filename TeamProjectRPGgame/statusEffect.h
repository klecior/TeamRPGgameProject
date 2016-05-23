#pragma once
#include "gameObject.h"
#include "messageBus.h"

//Events
#include "hitPlayerEvent.h"
#include"entityDeletedEvent.h"
#include"statusEffectEndedEvent.h"


class statusEffect :
	public gameObject
{
public:
	statusEffect();
	statusEffect::statusEffect(gameObject *targetAddress);
	~statusEffect();
	int getDuration();
	int getStartTime();
	int getRemainingTime();
	virtual void update();

protected:
	long int startTime, duration, endTime, remainingTime;
	gameObject *target;
};

