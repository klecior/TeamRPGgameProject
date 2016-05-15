#pragma once
#include "abstractEvent.h"


class playAudioEvent : public abstractEvent
{
public:

	virtual eventTypeId getEventType()const override { return playAudioMessage; }

};