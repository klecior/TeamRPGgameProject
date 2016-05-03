#pragma once
#include<SDL.h>

enum keys{up,down,left,right,space, esc};
class inputListener
{
	public:	
	inputListener();
	~inputListener();

	keys listenForInput(SDL_Event &evt); //returns keyboard press.
	keys listenForRelease(SDL_Event &evt); //returns keyboard press.
};