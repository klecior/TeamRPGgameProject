#include "msgEvent.h"


msgEvent::msgEvent()
{
	eventID		= 0;
	intData		= 0;
	boolData	= false;
}

msgEvent::msgEvent(int id, int iData, bool bData)
{
	eventID		=	id;
	intData		=	iData;
	boolData	=	bData;
}