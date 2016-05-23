#pragma once
#include<vector>
#include"statusEffect.h"

#include"addStatusEffectEvent.h"
class statusEffectQueue: observer
{
public:
	statusEffectQueue();
	
	~statusEffectQueue();

	void update();
	

protected:
	std::vector<statusEffect> queue;
	void handleMessage(abstractEvent* msgEvent);
	void addStatusEffect(abstractEvent* msgEvent);
	void statusEffectEnded(abstractEvent* msgEvent);
};

