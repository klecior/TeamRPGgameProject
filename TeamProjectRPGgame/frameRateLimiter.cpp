#include "frameRateLimiter.h"

frameRateLimiter*	frameRateLimiter::psharedframeRateLimiter = NULL;

frameRateLimiter* frameRateLimiter::sharedFrameRateLimiter()
{	
	if(psharedframeRateLimiter == NULL){psharedframeRateLimiter = new frameRateLimiter();}
	return psharedframeRateLimiter;
}


frameRateLimiter::frameRateLimiter()
{
	timeNow = SDL_GetTicks() / 60;
	timeLast = timeNow;
	frameDelta = 0;
}

void frameRateLimiter::setDelta()
{
	frameDelta = timeNow - timeLast;
	timeLast = timeNow;
}

void frameRateLimiter::endFrame()
{
	timeNow = SDL_GetTicks() / 60;
	//std::cout<<"delta was: "<<frameDelta<<std::endl;
}

