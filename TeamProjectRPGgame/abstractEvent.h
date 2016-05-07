#pragma once

#include "messages.h"
//**abstractEvent class is an abstract class of which all the message types will derive from**//
class abstractEvent
{
public:
	typedef int	eventTypeId;							// makes it so "eventTypeId_t" becomes the same variable as "int", basically using int under a different name for clarity of what it's used for.
	virtual eventTypeId	getEventType() const = 0;		//This function will be overwriten by the deriving classes, giving back the id, or "message type".
};

