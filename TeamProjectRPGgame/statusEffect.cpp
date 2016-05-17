#include "statusEffect.h"

statusEffect::statusEffect()
{
	target = nullptr;
}

statusEffect::statusEffect(gameObject *targetAddress)
{
	target = targetAddress;
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	remainingTime = endTime - startTime;
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

void statusEffect::update()
{
	std::cout << "Testing Base Status Effect"<<std::endl;
	messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(10));
	remainingTime = SDL_GetTicks() - endTime;
	std::cout << remainingTime;
}
