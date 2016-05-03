#include "inputListener.h"

inputListener::inputListener(){}
inputListener::~inputListener(){}

keys inputListener::listenForInput(SDL_Event &evt)
{
	if(evt.type == SDL_KEYDOWN)
	{
		if(evt.key.keysym.sym == SDLK_RIGHT || evt.key.keysym.sym == SDLK_d){return right;	}
		if(evt.key.keysym.sym == SDLK_LEFT  || evt.key.keysym.sym == SDLK_a){return left;	}
		if(evt.key.keysym.sym == SDLK_UP    || evt.key.keysym.sym == SDLK_w){return up;	}
		if(evt.key.keysym.sym == SDLK_DOWN  || evt.key.keysym.sym == SDLK_s){return down;	}
		if(evt.key.keysym.sym == SDLK_ESCAPE|| evt.key.keysym.sym == SDLK_p){return esc;	}

		if(evt.key.keysym.sym == SDLK_SPACE){return space;}
		
	}

}

keys inputListener::listenForRelease(SDL_Event &evt)
{

	if(evt.type == SDL_KEYUP)
	{
		if(evt.key.keysym.sym == SDLK_RIGHT || evt.key.keysym.sym == SDLK_d){return right;	}
		if(evt.key.keysym.sym == SDLK_LEFT  || evt.key.keysym.sym == SDLK_a){return left;	}
		if(evt.key.keysym.sym == SDLK_UP    || evt.key.keysym.sym == SDLK_w){return up;	}
		if(evt.key.keysym.sym == SDLK_DOWN  || evt.key.keysym.sym == SDLK_s){return down;	}
		if(evt.key.keysym.sym == SDLK_ESCAPE|| evt.key.keysym.sym == SDLK_p){return esc;	}

		if(evt.key.keysym.sym == SDLK_SPACE){return space;}
	}

}