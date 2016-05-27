#include "statusEffect.h"

statusEffect::statusEffect()
{
	target = nullptr;
}

void statusEffect::init(gameObject *targetAddress)
{
	duration = 5000;
	target = targetAddress;
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	tickEnd = startTime + 1000;
	currentTime = SDL_GetTicks();
	objectType = statusEffectT;

	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, statusEffectT, this));

	//Debug
	std::cout << "Start Time Is: " << startTime << std::endl;
	std::cout << "END TIME IS: " << endTime << std::endl;
}

statusEffect::statusEffect(gameObject *targetAddress)
{
	init(targetAddress);
}

statusEffect::~statusEffect()
{
	target = nullptr;
	std::cout << "Status effect ended" << std::endl;
}

int statusEffect::getDuration()
{
	return duration;
}

int statusEffect::getStartTime()
{
	return startTime;
}

int statusEffect::getRemainingTime()
{
	return endTime-currentTime;
}

void statusEffect::effect()
{
	messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(10));
}

void statusEffect::update()
{
	
	//remainingTime = endTime - SDL_GetTicks();
	//std::cout << "Time Remaining " << remainingTime / 1000 << std::endl;


	if (currentTime >= tickEnd)
	{
		std::cout << "Tick Ended" << std::endl;
		effect();
		tickEnd += 1000;
	}
	else
	{
		currentTime = SDL_GetTicks();
	}

	if (endTime-currentTime <= 0)
	{
		messageBus::sharedMessageBus()->sendMessage(statusEffectEndedEvent());
		std::cout << "Status Effect ended" << std::endl;
		std::cout << "Is alive = " << getAlive() << std::endl;
		alive = false;
	}
}
