#include "movePlayerEvent.h"

movePlayerEvent::movePlayerEvent(bool isUp, bool isDown, bool isLeft, bool isRight)
{
	upPressed		=	isUp;
	downPressed		=	isDown;
	leftPressed		=	isLeft;
	rightPressed	=	isRight;
}