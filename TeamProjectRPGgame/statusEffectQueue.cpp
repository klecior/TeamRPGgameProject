#include "statusEffectQueue.h"


#pragma region Constructors And Destructors
statusEffectQueue::statusEffectQueue()
{
	//REGISTERING NEW EVENT LISTENERS
	messageBus::sharedMessageBus()->registerListener(addStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->registerListener(statusEffectEndedMessage, this);
	messageBus::sharedMessageBus()->registerListener(removeAllStatusEffectMessage, this);

	std::cout << "STATUS QUEUE STARTED" << std::endl;
}

statusEffectQueue::~statusEffectQueue()
{
	//REMOVING EVENT LISTENERS
	messageBus::sharedMessageBus()->unRegisterListener(removeAllStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(statusEffectEndedMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(removeStatusEffectMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(addStatusEffectMessage, this);
}
#pragma endregion

#pragma region Message Handling
void statusEffectQueue::handleMessage(abstractEvent& msgEvent)
{
	//Pass in the message event for handling

	//Storing the message type
	int msgType = msgEvent.getEventType();

	//Checking message type for whether statusEffect is being added or removed
	if (msgType == addStatusEffectMessage) { addStatusEffect(&msgEvent); }
	if (msgType == statusEffectEndedMessage) { statusEffectEnded(&msgEvent); }
}

void statusEffectQueue::addStatusEffect(abstractEvent* msgEvent)
{
	//Pass in the message event
	
	//Casting message event to the addStatusEffectEvent type
	addStatusEffectEvent& addingStatus = *(addStatusEffectEvent*)msgEvent;

	//Switch statement to check which statusEffect type was requested
	switch (addingStatus.statusToGive)
	{
	case testStatus:
		//Abstract Status Effect (Basic Damage Over Time)
		queue.push_back(new statusEffect(addingStatus.targetCharacter));
		break;

	case onFireEffect:
		//On Fire Status Effect
		queue.push_back(new onFire(addingStatus.targetCharacter));
		break;

	case speedBoostEffect:
		//Speed Boost Status Effect
		queue.push_back(new speedBoost(addingStatus.targetCharacter));
		break;

	default:
		throw invalid_argument("Not an appropriate statusEffect");
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
			
			if (queue.at(i)->getRemainingTime() <= 0)
			{
				queue.at(i)->setAlive(false);
				//delete queue.at(i);																									//deletes the actual object, calls it's destructor.
				queue.erase(queue.begin() + i);
			}
		}
	}
}
#pragma endregion

void statusEffectQueue::update()
{
	//The status effect queue is not empty, will loop through all effects and apply their effects if they are ready.
	if (!queue.empty())
	{
		for (int i = 0; i < queue.size(); i++)
		{
			queue.at(i)->update();
		}
	}
}

