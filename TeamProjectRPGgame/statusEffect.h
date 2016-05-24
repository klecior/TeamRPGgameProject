#pragma once
#include "gameObject.h"
#include "messageBus.h"

//Events
#include "hitPlayerEvent.h"
#include"entityDeletedEvent.h"
#include"statusEffectEndedEvent.h"
#include"entityCreatedEvent.h"


class statusEffect :
	public gameObject
{
public:
	statusEffect();
	statusEffect(gameObject *targetAddress);
	~statusEffect();
	int getDuration();
	int getStartTime();
	int getRemainingTime();
	virtual void effect();
	void update();

	virtual void init(gameObject *targetAddress);

protected:
	int duration, startTime, endTime, tickEnd, currentTime;
	gameObject *target;
};

