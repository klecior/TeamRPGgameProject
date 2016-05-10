#pragma once
#include "abstractEvent.h"
#include <iostream>

class castSpellEvent : public abstractEvent
{
public:
	castSpellEvent(int spell);
	int spellName;

	virtual eventTypeId getEventType()const override { return castSpellMessage; }

};