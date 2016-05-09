#pragma once

#include "abstractEvent.h"

class getPlayerStatsEvent : public abstractEvent
{
	public:

		virtual eventTypeId getEventType()const override {return getPlayerStatsMessage;}

		//c = current, m = max

		float cHealth;
		float mHealth;
		float cStamina;
		float mStamina;
		float cMana;
		float mMana;
};