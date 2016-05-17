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
	currentTime = SDL_GetTicks();
	objectType = "statusEffectT";

	//Debug
	std::cout << "END TIME IS: " << endTime << std::endl;
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
	//std::cout << "Testing Base Status Effect"<<std::endl;
	currentTime = SDL_GetTicks();

	if (currentTime %1000 == 0)
	{
		std::cout << "Time Remaining " << endTime - currentTime / 1000 << std::endl;
		messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(5));
	}
	//std::cout << remainingTime;

	if (endTime - currentTime <=0)
	{
		alive = false;
		std::cout << "Status Effect ended" << std::endl;
	}
}
