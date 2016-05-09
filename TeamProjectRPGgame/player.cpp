#include "player.h"


player::player(void)
{
	idleState = nullptr;
	moveState = nullptr;

	isMoving = false;

	health		= 100;
	stamina		= 100;
	mana		= 100;

	totalDefenceTreshold = 0;

	//registers//
	messageBus::sharedMessageBus()->registerListener(movePlayerMessage,this);
	messageBus::sharedMessageBus()->registerListener(hitPlayerMessage, this);
	messageBus::sharedMessageBus()->registerListener(changeHealthMessage, this);
	messageBus::sharedMessageBus()->registerListener(changeStaminaMessage, this);
	//---------//


	objectType = "player";
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME,objectType,this));
}


player::~player(void)
{
	messageBus::sharedMessageBus()->unRegisterListener(movePlayerMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(hitPlayerMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(changeHealthMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStaminaMessage, this);
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
		
		if (health <= 0)
		{

			std::cout << "player is DED" << std::endl;
		}
	}

}
void player::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == movePlayerMessage)	{ playerMovement(&msgEvent);	}
	if(msgType == hitPlayerMessage)		{ onHit(&msgEvent);				}
	if(msgType == changeHealthMessage)  { changeHealth(&msgEvent);		}

}

#pragma region event handlers

void player::playerMovement(abstractEvent* msgEvent)
{
	//cast
	movePlayerEvent& playerMoving = *(movePlayerEvent*)msgEvent;

	if(playerMoving.downPressed)	{ position.y += 3; isMoving = true; }
	if(playerMoving.upPressed)		{ position.y -= 3; isMoving = true; }
	if(playerMoving.leftPressed)	{ position.x -= 3; isMoving = true; }
	if(playerMoving.rightPressed)	{ position.x += 3; isMoving = true; }

}

void player::onHit(abstractEvent* msgEvent)
{
	//cast
	hitPlayerEvent& playerHit = *(hitPlayerEvent*)msgEvent;


	//calculate damage taken based on the player defence
	int totalDamageTaken = 0;
	totalDamageTaken = playerHit.damage - totalDefenceTreshold;
	//prevents from healing the player
	if (totalDamageTaken < 0) { totalDamageTaken = 0; }
	
	//subtract the damage taken from the health
	int finalHealthAfterHit = health - totalDamageTaken;
	
	//change the health and update all displays
	messageBus::sharedMessageBus()->sendMessage(changeHealthEvent(finalHealthAfterHit));
}

void player::changeHealth(abstractEvent* msgEvent)
{
	//cast
	changeHealthEvent& newHealth = *(changeHealthEvent*)msgEvent;

	health = newHealth.newHealth;
	std::cout << "changed health to: " << health << std::endl;
}

#pragma endregion

