#pragma once

class msgEvent
{
public:
	msgEvent();
	msgEvent(int id, int iData, bool bData);
	int		eventID;
	int		intData;
	bool	boolData;
};
