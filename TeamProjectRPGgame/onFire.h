#pragma once
#include "statusEffect.h"
class onFire :
	public statusEffect
{
public:
	
	onFire();
	onFire(gameObject *targetAddress);
	~onFire();

	void init(gameObject *targetAddress);
	void effect();

	int damage;
};

