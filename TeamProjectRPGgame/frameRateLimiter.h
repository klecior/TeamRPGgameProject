#pragma once

#include <iostream>
#include "constants.h"
#include <SDL.h>


class frameRateLimiter
{
protected:

	frameRateLimiter(void);
	static frameRateLimiter*	psharedframeRateLimiter;

	double timeNow;
	double timeLast;

public:

	~frameRateLimiter(void);

	static frameRateLimiter*	sharedFrameRateLimiter();

	double frameDelta;

	void setDelta();
	void endFrame();

};

