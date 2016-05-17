#include "addStatusEffectEvent.h"

addStatusEffectEvent::addStatusEffectEvent(int statusToAdd, gameObject *target)
{
	switch (statusToAdd)
	{
	case testStatus:
		std::cout << "Adding test Status Effect" << std::endl;
		statusToGive = new statusEffect(target);
		break;

	default:
		std::cout << "Failed to add status effect" << std::endl;
		break;
	}
}
