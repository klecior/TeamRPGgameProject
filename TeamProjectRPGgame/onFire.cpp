#include "onFire.h"


void onFire::init(gameObject *targetAddress)
{
	duration = 10000;
	target = targetAddress;
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	tickEnd = startTime + 1000;
	currentTime = SDL_GetTicks();
	objectType = statusEffectT;

	damage = 30;

	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, objectType, this));

	//Debug
	std::cout << "Start Time Is: " << startTime << std::endl;
	std::cout << "END TIME IS: " << endTime << std::endl;
}


onFire::onFire()
{
	
}

onFire::onFire(gameObject *targetAddress)
{
	init(targetAddress);
}

onFire::~onFire()
{
	target = nullptr;
}


void onFire::effect()
{
	messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(damage));
}