#pragma once

#include "observer.h"
#include "messages.h"
#include <vector>
#include <iostream>
#include "msgEvent.h"
#include "gameObject.h"
//**messageBus clas is responsible for recival, and distribution of messages**//


class messageBus
{
protected:
	messageBus(void);
	static messageBus*	pSharedMessageBus;

	std::vector<observer*> registeredSystems;
	std::vector<observer*> registeredObjects;



public:

	~messageBus(void);
	static messageBus*	sharedMessageBus();

	void registerSystem(observer* systemToRegister);
	void registerObject(observer* objectToRegister);
	void sendMessageS(int message);						//send message to systems
	void sendMessageS(msgEvent& msg);
	void sendMessageO(int message);						//send message to objects


};

