#pragma once
#include "abstractevent.h"
class leftMouseClickEvent :
	public abstractEvent
{
public:

	leftMouseClickEvent(int mX, int mY);
	virtual eventTypeId getEventType()const override {return leftMouseClickMessage;}

	int mouseXwas;
	int mouseYwas;
};

