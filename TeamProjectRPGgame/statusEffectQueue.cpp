#include "statusEffectQueue.h"



statusEffectQueue::statusEffectQueue()
{
	messageBus::sharedMessageBus()->registerListener(addStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeAllStatusEffectMessage, this);

	std::cout << "STATUS QUEUE STARTED" << std::endl;
}

statusEffectQueue::~statusEffectQueue()
{
	messageBus::sharedMessageBus()->unRegisterListener(removeAllStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(addStatusEffectMessage, this);
}

void statusEffectQueue::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if (msgType == addStatusEffectMessage)
	{
		addStatusEffect(&msgEvent);
	}
}

void statusEffectQueue::addStatusEffect(abstractEvent* msgEvent)
{
	//Cast
	addStatusEffectEvent& addingStatus = *(addStatusEffectEvent*)msgEvent;

	queue.push_back(addingStatus.statusToGive);
}

void statusEffectQueue::update()
{
	//std::cout << "IS THE STATUS QUEUE EMPTY... ";
	//std::cout << "THERE ARE " << queue.size()<< " STATUS EFFECTS TO HANDLE" << std::endl;
	for (int i = 0; i < queue.size(); i++)
	{
		queue.at(i).update();
	}
	//std::cout<<"THERE ARE NO MORE STATUS EFFECTS TO HANDLE" << std::endl;
}
