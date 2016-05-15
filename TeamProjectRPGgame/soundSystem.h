#pragma once

#include "observer.h"
#include "messageBus.h"
#include "messages.h"
#include "playAudioEvent.h"

class soundSystem : public observer
{
public:
	soundSystem();
	~soundSystem();

	void handleMessage(abstractEvent & msgEvent);
	void playAudio(abstractEvent* msgEvent);

private:

};