#include "soundSystem.h"

soundSystem::soundSystem() 
{
	messageBus::sharedMessageBus()->registerListener(playAudioMessage, this);		//Sets up event listener
}

soundSystem::~soundSystem() 
{
	messageBus::sharedMessageBus()->unRegisterListener(playAudioMessage, this);	//Unregusters when system dies dies
}

void soundSystem::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if (msgType == playAudioMessage) { playAudio(&msgEvent); }

}

void soundSystem::playAudio(abstractEvent * msgEvent)
{
	playAudioEvent& playAudioV = *(playAudioEvent*)msgEvent;
	filePath = playAudioV.filePath;
	if (playAudioV.isPlaying == true)
	{
		if (playAudioV.isMusic)
		{
			tempMusic = assetManager::sharedassetManager()->getMusic(filePath);
		}
		else
		{
			tempChunk = assetManager::sharedassetManager()->getChunk(filePath);
		}
	}
}
