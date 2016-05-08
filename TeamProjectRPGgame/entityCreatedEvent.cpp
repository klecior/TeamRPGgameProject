#include "entityCreatedEvent.h"

entityCreatedEvent::entityCreatedEvent(int belongsToState, std::string typeOfEntity, gameObject* object)
{
	atState			= belongsToState;
	type			= typeOfEntity;
	createdObject	= object;
	std::cout<<"created entity of type: "<<type<<std::endl;
}