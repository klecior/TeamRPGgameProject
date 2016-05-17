#include "addStatusEffectEvent.h"

addStatusEffectEvent::addStatusEffectEvent(int statusToAdd, gameObject *target)
{
	switch (statusToAdd)
	{
	testStatus:
		statusToGive = new statusEffect(target);
		break;

	default:
		break;
	}
}
