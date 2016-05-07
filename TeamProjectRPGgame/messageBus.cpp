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


void messageBus::registerListener(int messageType, observer* object)
{
	//adds the object to the right list
	registers[messageType].push_back(object);
}

void messageBus::unRegisterListener(int messageType, observer* object)
{
	for(int i = 0; i < registers[messageType].size(); i++)
	{
		if(registers[messageType].at(i) == object)
		{
			registers[messageType].erase(registers[messageType].begin()+i);
		}
	}
}

void messageBus::sendMessage(abstractEvent& msgEvent)
{
	//get type
	int messageType = msgEvent.getEventType();

	//sends the message to every object listening for it.
	for(int j = 0; j<registers[messageType].size(); j++)
	{
		registers[messageType].at(j)->handleMessage(msgEvent);
	}
}
