#include "soundSystem.h"

soundSystem::soundSystem() 
{
	messageBus::sharedMessageBus()->registerListener(playAudioMessage, this);		//Sets up event listener
	curChannel = 0;
}

soundSystem::~soundSystem() 
{
	messageBus::sharedMessageBus()->unRegisterListener(playAudioMessage, this);	//Unregusters when system dies 
}
/*----------------------------------------------------------------------------
	used to recieve the event then calls to the play audio function
--------------------------------------------------------------------------------*/
void soundSystem::handleMessage(abstractEvent& msgEvent)	
{
	int msgType = msgEvent.getEventType();

	if (msgType == playAudioMessage) { playAudio(&msgEvent); }

}


/*--------------------------------------------------------------------------------
	Play audio function
		Gets the message from the event being cast
		takes 3 variables from the event 
			FilePath = Path to the audio file
			isMusic	= is true if the audio is music
			isPlaying = if true then audio is playing else if false then stops the audio
----------------------------------------------------------------------------------------*/
void soundSystem::playAudio(abstractEvent * msgEvent)
{
	playAudioEvent& playAudioV = *(playAudioEvent*)msgEvent;
	filePath = playAudioV.filePath;
	if (playAudioV.isPlaying == true)
	{
		if (playAudioV.isMusic)
		{
			tempMusic = assetManager::sharedAssetManager()->getMusic(filePath);
		}
		else
		{
			tempChunk = assetManager::sharedAssetManager()->getChunk(filePath);
			
			Mix_PlayChannel(curChannel, tempChunk, 0);
			curChannel++;
			if (curChannel > 8) curChannel = 0;		//temmporary soloution to switch channels just switched channel whenever an audio channel is used
		}
	}
}
