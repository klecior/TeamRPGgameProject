#include "statusEffect.h"

statusEffect::statusEffect()
{
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	remainingTime = endTime - startTime;
}

statusEffect::statusEffect(gameObject &targetAddress)
{
	target = targetAddress;
}

statusEffect::~statusEffect()
{
}

int statusEffect::getDuration()
{
	return 0;
}

int statusEffect::getStartTime()
{
	return 0;
}

void statusEffect::effect()
{
	std::cout << "Testing Base Status Effect"<<std::endl;
	messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(10));
	remainingTime = SDL_GetTicks() - endTime;
}
