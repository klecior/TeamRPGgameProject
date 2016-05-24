#pragma once
#include<vector>

//STATUS EFFECT TYPES
#include"statusEffect.h"
#include"onFire.h"
#include"speedBoost.h"
/*
#include"armourBoost.h"
#include"healing.h"
*/


#include"addStatusEffectEvent.h"
class statusEffectQueue: observer
{
public:

	statusEffectQueue();
	~statusEffectQueue();

	//Function which handles the updating of thq effects held within the queue.
	void update();
	

protected:
	//The vector which holds all possible statusEffects.
	std::vector<statusEffect*> queue;
	
	//Function which handles messages passed by the message bus.
	void handleMessage(abstractEvent& msgEvent);
	
	//Function which adds a new statusEffect to the queue of effects.
	void addStatusEffect(abstractEvent* msgEvent);

	//Function which handles the removal of statusEffects from the queue when they send the message that they have.
	void statusEffectEnded(abstractEvent* msgEvent);
};

