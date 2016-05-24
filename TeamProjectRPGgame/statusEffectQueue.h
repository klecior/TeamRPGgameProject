#pragma once
#include<vector>

//STATUS EFFECT TYPES
#include"statusEffect.h"
#include"onFire.h"


#include"addStatusEffectEvent.h"
class statusEffectQueue: observer
{
public:
	statusEffectQueue();
	
	~statusEffectQueue();

	void update();
	

protected:
	std::vector<statusEffect*> queue;
	void handleMessage(abstractEvent& msgEvent);
	void addStatusEffect(abstractEvent* msgEvent);
	void statusEffectEnded(abstractEvent* msgEvent);
};

