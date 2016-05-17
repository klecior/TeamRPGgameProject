#pragma once
#include "abstractEvent.h"
#include <string>

class playAudioEvent : public abstractEvent
{
public:
	playAudioEvent(std::string path, bool music, bool playing);
	virtual eventTypeId getEventType()const override { return playAudioMessage; }
	std::string filePath;
	bool isMusic, isPlaying;
};