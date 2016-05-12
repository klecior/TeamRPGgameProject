#pragma once

#include "observer.h"
#include "abstractEvent.h"
#include <vector>
#include <iostream>
#include <map>					//the map is a useful container

//**messageBus class is responsible for recival, and distribution of messages**//
class messageBus
{
protected:
	messageBus(void);
	static messageBus*	pSharedMessageBus;

	//this map is a list, containing a vector of observer pointers for every message type. It effectively lists every object that listens to a particular message.
	std::map<int,std::vector<observer*>> registers;

public:

	~messageBus(void);
	static messageBus*	sharedMessageBus();

	//register a listener. The first argument is what kind of message it wants to listen for, second is the address of object listening to it.
	void registerListener(int messageType, observer* object);

	//unregister a listener. Removes the object from the list.
	void unRegisterListener(int messageType, observer* object);

	//send a event/message. The function itself handles where to send it.
	void sendMessage(abstractEvent& msgEvent);

};

