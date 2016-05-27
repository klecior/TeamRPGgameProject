#include "speedBoost.h"

void speedBoost::init(gameObject *targetAddress)
{
	duration = 10000;
	target = targetAddress;
	startTime = SDL_GetTicks();
	endTime = (SDL_GetTicks() + duration);
	tickEnd = startTime + 1000;
	currentTime = SDL_GetTicks();
	objectType = statusEffectT;

	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, statusEffectT, this));

	//addStatusEffectEvent& addingStatus = *(addStatusEffectEvent*)msgEvent;
	//targettedCharacter = *(player*)target;

	//player& test = *(player*)targetAddress;
	//targettedCharacter = test;

	//Debug
	std::cout << "Start Time Is: " << startTime << std::endl;
	std::cout << "END TIME IS: " << endTime << std::endl;
}

void speedBoost::effect()
{
	
	
}

speedBoost::speedBoost()
{

}

speedBoost::speedBoost(gameObject* target)
{
	init(target);
}

speedBoost::~speedBoost()
{
}
