#pragma once
#include <SDL_mixer.h>

#include "observer.h"
#include "messageBus.h"
#include "messages.h"
#include "playAudioEvent.h"
#include "AssetManager.h"

class soundSystem : public observer
{
protected:
	std::string filePath;
	Mix_Chunk* tempChunk;
	Mix_Music* tempMusic;
public:
	soundSystem();
	~soundSystem();

	void handleMessage(abstractEvent & msgEvent);
	void playAudio(abstractEvent* msgEvent);

private:

};