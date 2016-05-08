#include "entityDeletedEvent.h"

entityDeletedEvent::entityDeletedEvent(int belongsToState, gameObject* object)
{
	atState			=	belongsToState;
	deletedObject	=	object;
}