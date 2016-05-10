#pragma once
#include "gameObject.h"
#include "messageBus.h"
class statusEffect :
	public gameObject
{
public:
	statusEffect();
	~statusEffect();
	int getDuration();
	int getStartTime();
	virtual void effect();
protected:
	int startTime, duration, endTime, remainingTime;
	gameObject &target;
};

