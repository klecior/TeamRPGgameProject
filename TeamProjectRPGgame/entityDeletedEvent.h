#pragma once
#include "abstractevent.h"
#include <string>
#include "gameObject.h"
class entityDeletedEvent :
	public abstractEvent
{
public:

	entityDeletedEvent(int belongsToState, gameObject* object);
	virtual eventTypeId getEventType()const override {return entityDeletedMessage;}
	
	int	atState;
	gameObject*	deletedObject;

};

