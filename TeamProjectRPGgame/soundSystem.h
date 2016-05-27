#pragma once
#include <SDL_mixer.h>
#include <iostream> 

#include "observer.h"
#include "messageBus.h"
//#include "messages.h"
#include "playAudioEvent.h"
#include "AssetManager.h"

class soundSystem : public observer
{
protected:
	std::string filePath;
	Mix_Chunk* tempChunk;
	Mix_Music* tempMusic;
	short int curChannel;
public:
	soundSystem();
	~soundSystem();

	void handleMessage(abstractEvent & msgEvent);
	void playAudio(abstractEvent* msgEvent);

private:

};