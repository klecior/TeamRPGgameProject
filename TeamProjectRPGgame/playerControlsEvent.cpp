#include "playerControlsEvent.h"

playerControlsEvent::playerControlsEvent(bool isUp, bool isDown, bool isLeft, bool isRight, bool isLshift)
{
	upPressed		=	isUp;
	downPressed		=	isDown;
	leftPressed		=	isLeft;
	rightPressed	=	isRight;
	lShiftPressed	=	isLshift;
}