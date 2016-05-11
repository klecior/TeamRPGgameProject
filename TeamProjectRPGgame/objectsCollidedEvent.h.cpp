#include "objectsCollidedEvent.h"

objectsCollidedEvent::objectsCollidedEvent(gameObject& colObject1, gameObject& colObject2)
{
	object1 = &colObject1;
	object2 = &colObject2;
}