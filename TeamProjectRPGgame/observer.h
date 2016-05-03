#pragma once
//message data type for allowing passing, and reciving data back between objects, without them being coupled together.

#include "msgEvent.h"
class observer
{
private:

public:
	
	virtual void handleMessage(int message);						//simple message with no extra data.
	virtual void handleMessage(msgEvent& message);					//message containing additional data.
	
};