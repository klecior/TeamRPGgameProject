#include "entityCreatedEvent.h"

entityCreatedEvent::entityCreatedEvent(int belongsToState, int typeOfEntity, gameObject* object)
{
	atState			= belongsToState;
	type			= typeOfEntity;
	createdObject	= object;
	std::cout<<"created entity of type: "<<type<<std::endl;
}