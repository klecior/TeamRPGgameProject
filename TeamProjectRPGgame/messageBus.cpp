#include "messageBus.h"

messageBus*	messageBus::pSharedMessageBus = NULL;
messageBus* messageBus::sharedMessageBus()
{	
	if(pSharedMessageBus == NULL){pSharedMessageBus = new messageBus();}
	return pSharedMessageBus;
}


messageBus::messageBus(void)
{

}


messageBus::~messageBus(void)
{
}



#pragma region registering observers
void messageBus::registerSystem(observer* systemToRegister)
{
	registeredSystems.push_back(systemToRegister);
	std::cout<<"system registered"<<std::endl;
}

void messageBus::registerObject(observer* objectToRegister)
{
	registeredObjects.push_back(objectToRegister);
	std::cout<<"object registered"<<std::endl;
}
#pragma endregion //registering various groups of observers.

#pragma region sendingMessages

void messageBus::sendMessageS(int message)
{
	for(int i = 0; i < registeredSystems.size(); i++)
	{
		registeredSystems.at(i)->handleMessage(message);
	}
}

void messageBus::sendMessageS(msgEvent& msg)
{
	for(int i = 0; i < registeredSystems.size(); i++)
	{
		registeredSystems.at(i)->handleMessage(msg);
	}
};

void messageBus::sendMessageO(int message)
{

	for(int i = 0; i < registeredObjects.size(); i++)
	{
		registeredObjects.at(i)->handleMessage(message);
	}
}

#pragma endregion	//code for sending messages to different groups/types of objects.