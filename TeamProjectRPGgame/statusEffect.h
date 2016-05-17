#pragma once
#include "gameObject.h"
#include "messageBus.h"

//Events
#include "hitPlayerEvent.h"
#include"entityDeletedEvent.h"


class statusEffect :
	public gameObject
{
public:
	statusEffect();
	statusEffect::statusEffect(gameObject *targetAddress);
	~statusEffect();
	int getDuration();
	int getStartTime();
	virtual void update();

protected:
	int startTime, duration, endTime, currentTime;
	gameObject *target;
};

