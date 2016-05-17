#include "playAudioEvent.h"

playAudioEvent::playAudioEvent(std::string path, bool music, bool playing)
{
	filePath = path;
	isPlaying = playing;
	isMusic = music;
}
