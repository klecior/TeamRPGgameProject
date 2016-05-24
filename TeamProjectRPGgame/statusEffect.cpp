#include "statusEffect.h"

statusEffect::statusEffect()
{
	target = nullptr;
}

statusEffect::statusEffect(gameObject *targetAddress)
{
	duration = 5000;
	target = targetAddress;
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	tickEnd =startTime+1000;
	currentTime = SDL_GetTicks();
	objectType = "statusEffectT";

	//Debug
	std::cout << "Start Time Is: " << startTime << std::endl;
	std::cout << "END TIME IS: " << endTime << std::endl;
}

statusEffect::~statusEffect()
{
	target = nullptr;
}

int statusEffect::getDuration()
{
	return 0;
}

int statusEffect::getStartTime()
{
	return 0;
}

int statusEffect::getRemainingTime()
{
	return 0;
}

void statusEffect::update()
{
	
	//remainingTime = endTime - SDL_GetTicks();
	//std::cout << "Time Remaining " << remainingTime / 1000 << std::endl;


	if (currentTime >= tickEnd)
	{
		std::cout << "Tick Ended" << std::endl;
		messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(10));
		tickEnd += 1000;
	}
	else
	{
		currentTime = SDL_GetTicks();
	}

	if (endTime-currentTime == 0)
	{
		messageBus::sharedMessageBus()->sendMessage(statusEffectEndedEvent());
		std::cout << "Status Effect ended" << std::endl;
	}
}
