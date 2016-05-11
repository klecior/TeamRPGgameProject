#pragma once
#include "abstractevent.h"
#include "gameObject.h"

class objectsCollidedEvent :
	public abstractEvent
{
public:

	objectsCollidedEvent(gameObject& colObject1, gameObject& colObject2);
	virtual eventTypeId getEventType()const override {return objectsCollidedMessage;}
	
	gameObject* object1;
	gameObject* object2;
};

