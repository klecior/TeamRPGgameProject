#include "player.h"


player::player(void)
{
	idleState = nullptr;
	moveState = nullptr;

	isMoving = false;

	gameManager::sharedGameManager()->addToList(this,GAME);
	messageBus::sharedMessageBus()->registerObject(this);
	objectType = "player";
}


player::~player(void)
{
}

void player::loadOnCreation()
{
	if(finishedLoading == false)
	{
		
		idleState = SpriteManager::sharedSpriteManager()->getImage("Assets/Characters/Player/playerIdle.png");
		moveState = SpriteManager::sharedSpriteManager()->getImage("Assets/Characters/Player/playerMoving.png");

		changeImage(idleState);
		std::cout<<"Loaded player assets"<<std::endl;

		finishedLoading = true;
	}
}

void player::update()
{
	loadOnCreation();
	
	if(isMoving){changeImage(moveState);}
	else{changeImage(idleState);}





	isMoving = false;
}
void player::handleMessage(int message)
{
	
	if(message == movePleft)	{position.x		-=	2;	isMoving = true;	}
	if(message == movePright)	{position.x		+=	2;	isMoving = true;	}
	if(message == movePdown)	{position.y		+=	2;	isMoving = true;	}
	if(message == movePup)		{position.y		-=	2;	isMoving = true;	}

}

