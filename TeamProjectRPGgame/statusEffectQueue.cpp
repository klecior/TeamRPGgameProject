#include "statusEffectQueue.h"



statusEffectQueue::statusEffectQueue()
{
	messageBus::sharedMessageBus()->registerListener(addStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(statusEffectEndedMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeAllStatusEffectMessage, this);

	std::cout << "STATUS QUEUE STARTED" << std::endl;
}

statusEffectQueue::~statusEffectQueue()
{
	messageBus::sharedMessageBus()->unRegisterListener(removeAllStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(statusEffectEndedMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(addStatusEffectMessage, this);
}

void statusEffectQueue::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();
	
	std::cout << "Handling status events" << std::endl;
	
	if (msgType == addStatusEffectMessage) { addStatusEffect(&msgEvent); }

	if (msgType == statusEffectEndedMessage) { statusEffectEnded(&msgEvent); }
}

void statusEffectQueue::addStatusEffect(abstractEvent* msgEvent)
{
	//Cast
	addStatusEffectEvent& addingStatus = *(addStatusEffectEvent*)msgEvent;

	std::cout << "ADDDING STATUS" << std::endl;

	switch (addingStatus.statusToGive)
	{
	case testStatus:
		queue.push_back(new statusEffect(addingStatus.targetCharacter));
		break;

	default:
		break;
	}
}

void statusEffectQueue::statusEffectEnded(abstractEvent* msgEvent)
{
	std::cout << "Removing statusEffect" << std::endl;
	statusEffectEndedEvent& endedStatus = *(statusEffectEndedEvent*)msgEvent;
	if (!queue.empty())
	{
		for (int i = 0; i < queue.size(); i++)
		{
			
			if (queue.at(i).getRemainingTime() <= 0)
			{
				std::cout << "Stuff";
				queue.at(i).setAlive(false);
				
			}
		}
	}
}

void statusEffectQueue::update()
{
	//DEBUG TEXT
	//std::cout << "IS THE STATUS QUEUE EMPTY... ";
	//std::cout << "THERE ARE " << queue.size()<< " STATUS EFFECTS TO HANDLE" << std::endl;
	
	for (int i = 0; i < queue.size(); i++)
	{
		queue.at(i).update();
	}
}

