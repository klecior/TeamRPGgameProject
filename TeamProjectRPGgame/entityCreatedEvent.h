#pragma once
#include "abstractevent.h"
#include <string>
#include "gameObject.h"
class entityCreatedEvent :
	public abstractEvent
{
public:

	entityCreatedEvent(int belongsToState, std::string typeOfEntity, gameObject* object);
	virtual eventTypeId getEventType()const override {return entityCreatedMessage;}
	
	std::string type;
	int	atState;
	gameObject*	createdObject;

};

