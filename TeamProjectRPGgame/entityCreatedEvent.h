#pragma once
#include "abstractevent.h"
#include <string>
#include "gameObject.h"
class entityCreatedEvent :
	public abstractEvent
{
public:

	entityCreatedEvent(int belongsToState, int typeOfEntity, gameObject* object);
	virtual eventTypeId getEventType()const override {return entityCreatedMessage;}
	
	int type;
	int	atState;
	gameObject*	createdObject;

};

