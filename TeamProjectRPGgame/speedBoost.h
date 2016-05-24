#pragma once
#include "statusEffect.h"
#include "player.h"
class speedBoost :
	public statusEffect
{
public:
	speedBoost();
	speedBoost(gameObject *target);
	~speedBoost();
	void init(gameObject* targetCharacter);
	void effect();

protected:
	player* targettedCharacter;
};

