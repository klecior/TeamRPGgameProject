#include "addStatusEffectEvent.h"

addStatusEffectEvent::addStatusEffectEvent(int statusToAdd, gameObject *target)
{
	statusToGive = statusToAdd;
	targetCharacter = target;
}
