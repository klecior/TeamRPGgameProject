#pragma once

#include "abstractEvent.h"

//**the abstract class that every object will inherit from. Allows listening, and handling of events/messages**//
class observer
{
public:

	//handle message function takes in any event derived/inheriting the abstractEvent class, basically any existing event can be passed here.
	virtual void handleMessage(abstractEvent& msgEvent);

};

