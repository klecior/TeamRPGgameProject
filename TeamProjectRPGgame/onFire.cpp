#include "onFire.h"



onFire::onFire()
{
}


onFire::~onFire()
{
}


void onFire::effect()
{
	messageBus::sharedMessageBus()->sendMessage(hitPlayerEvent(1));
}