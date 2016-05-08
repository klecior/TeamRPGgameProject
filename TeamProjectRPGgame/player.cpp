#include "player.h"


player::player(void)
{
	idleState = nullptr;
	moveState = nullptr;

	isMoving = false;

	messageBus::sharedMessageBus()->registerListener(movePlayerMessage,this);

	objectType = "player";
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME,objectType,this));
}


player::~player(void)
{
	messageBus::sharedMessageBus()->unRegisterListener(movePlayerMessage,this);
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
	
	if(finishedLoading)
	{
		if(isMoving){changeImage(moveState);}
		else{changeImage(idleState);}

		isMoving = false;
	}

}
void player::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == movePlayerMessage) { playerMovement(&msgEvent); }

}

#pragma region event handlers

void player::playerMovement(abstractEvent* msgEvent)
{
	//cast
	movePlayerEvent& playerMoving = *(movePlayerEvent*)msgEvent;

	if(playerMoving.downPressed)	{ position.y += 3; isMoving = true; messageBus::sharedMessageBus()->sendMessage(entityDeletedEvent(GAME,this)); }
	if(playerMoving.upPressed)		{ position.y -= 3; isMoving = true; }
	if(playerMoving.leftPressed)	{ position.x -= 3; isMoving = true; }
	if(playerMoving.rightPressed)	{ position.x += 3; isMoving = true; }

}

#pragma endregion

