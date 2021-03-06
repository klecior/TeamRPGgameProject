#include "player.h"


player::player(void)
{

	idleState = nullptr;
	moveState = nullptr;

	isMoving		=	false;
	isSprinting		=	false;
	teleportReady	=	false;

	//vitals//
	maxHealth	= 500;
	health		= maxHealth;

	maxStamina	= 500;
	stamina		= maxStamina;
	
	maxMana		= 500;
	mana		= maxMana;

	manaRecovery	=	1;
	staminaRecovery	=	1;
	healthRecovery	=	1;
	//------//

	//speed//
	baseSpeed		= 10;
	movementSpeed	= baseSpeed;

	sprintModifier	= 3;
	sprintCost		= 20;	
	//-----//

	totalDefenceTreshold = 0;

	//registers//
	messageBus::sharedMessageBus()->registerListener(playerControlsMessage,this);
	messageBus::sharedMessageBus()->registerListener(hitPlayerMessage, this);
	messageBus::sharedMessageBus()->registerListener(changeHealthMessage, this);
	messageBus::sharedMessageBus()->registerListener(changeStaminaMessage, this);
	messageBus::sharedMessageBus()->registerListener(getPlayerStatsMessage, this);
	messageBus::sharedMessageBus()->registerListener(leftMouseClickMessage, this);
	messageBus::sharedMessageBus()->registerListener(castSpellMessage, this);
	//---------//


	objectType = playerT;
	hasCollision = true;
	belongsToState = GAME;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME,objectType,this));
}


player::~player(void)
{
	messageBus::sharedMessageBus()->unRegisterListener(playerControlsMessage,this);
	messageBus::sharedMessageBus()->unRegisterListener(hitPlayerMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(changeHealthMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(changeStaminaMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(getPlayerStatsMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(leftMouseClickMessage, this);
	messageBus::sharedMessageBus()->unRegisterListener(castSpellMessage, this);
}

void player::loadOnCreation()
{
	if(finishedLoading == false)
	{
		
		idleState = assetManager::sharedAssetManager()->getImage("Assets/Characters/Player/playerIdle.png");
		moveState = assetManager::sharedAssetManager()->getImage("Assets/Characters/Player/playerMoving.png");

		changeImage(idleState);

		std::cout<<"Loaded player assets"<<std::endl;

		collisionBox = position;

		finishedLoading = true;
	}
}

void player::update()
{
	loadOnCreation();
	
	if(finishedLoading)
	{
		static bool doOnce = false;
		if (!doOnce)
		{
			//send message
			messageBus::sharedMessageBus()->sendMessage(addStatusEffectEvent(onFireEffect, this));

	
			doOnce = true;
			std::cout << "Adding a status effect to player" << std::endl;
		}


		handleSprites();
		
		staminaRegen();

		if (health <= 0)
		{
			static bool triggerOnce = false;
			if(triggerOnce == false)
			{
				std::cout << "player is DED" << std::endl;
				triggerOnce = true;
				//alive = false;
			}

		}

	}

}


//this function changes how the player looks depending on various states such as idle, moving, sprinting, with effects etc.
void player::handleSprites()
{
	if(isMoving){changeImage(moveState);}
	else{changeImage(idleState);}

	isMoving = false;
}


void player::staminaRegen()
{

	if(isSprinting == false)
	{
		if(stamina < maxStamina)
		{
			messageBus::sharedMessageBus()->sendMessage(changeStaminaEvent(stamina + frameRateLimiter::sharedFrameRateLimiter()->frameDelta * staminaRecovery));
		}
		if(stamina > maxStamina)
		{
			messageBus::sharedMessageBus()->sendMessage(changeStaminaEvent(maxStamina));
		}
	}
}









#pragma region event handlers

void player::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == playerControlsMessage){ playerControls(&msgEvent);	}
	if(msgType == hitPlayerMessage)		{ onHit(&msgEvent);				}
	if(msgType == changeHealthMessage)  { changeHealth(&msgEvent);		}
	if(msgType == changeStaminaMessage)	{ changeStamina(&msgEvent);		}
	if(msgType == getPlayerStatsMessage){ getPlayerStats(&msgEvent);	}
	if(msgType == castSpellMessage)		{ spellHandler(&msgEvent);		}
	if(msgType == leftMouseClickMessage){ teleport(&msgEvent);			}

}


#pragma region movement
void player::playerControls(abstractEvent* msgEvent)
{
	//cast
	playerControlsEvent& playerMoving = *(playerControlsEvent*)msgEvent;

	//movement//
	if(playerMoving.lShiftPressed)
	{ 
		sprint();
	}
	else{ isSprinting	=	false; movementSpeed = baseSpeed;}

	walk(&playerMoving);
	//--------//



}

void player::walk(playerControlsEvent* controls)
{
	//double speedDelta = frameRateLimiter::sharedFrameRateLimiter()->frameDelta * movementSpeed;
	float tempSpeed = frameRateLimiter::sharedFrameRateLimiter()->frameDelta * movementSpeed;
	if(controls->downPressed)	{ position.y +=	tempSpeed; isMoving = true; }
	if(controls->upPressed)		{ position.y -=	tempSpeed; isMoving = true; }
	if(controls->leftPressed)	{ position.x -= tempSpeed; isMoving = true; }
	if(controls->rightPressed)	{ position.x += tempSpeed; isMoving = true; }
}

void player::sprint()
{

	if(stamina > sprintCost)
	{
		isSprinting = true;
		//std::cout<<"playerIsSprinting"<<std::endl;
		movementSpeed	=	baseSpeed * sprintModifier;
		int tempCost	=	frameRateLimiter::sharedFrameRateLimiter()->frameDelta * sprintCost;
		messageBus::sharedMessageBus()->sendMessage(changeStaminaEvent(stamina - tempCost));
	}
	else
	{
		isSprinting = false;
		movementSpeed = baseSpeed;
	}
}

void player::teleport(abstractEvent* msgEvent)
{
	if(teleportReady)
	{
		//cast
		leftMouseClickEvent& LeftClick = *(leftMouseClickEvent*)msgEvent;
		position.x = LeftClick.mouseXwas - (position.w/2);
		position.y = LeftClick.mouseYwas - (position.h/2);
		teleportReady = false;
	}
}


#pragma endregion all of movement related functions

void player::spellHandler(abstractEvent* msgEvent)
{
	castSpellEvent& spell = *(castSpellEvent*)msgEvent;
	int spellType = spell.spellName;

	if (spellType == teleportSpell) 
	{
		teleportReady = true;
	}
}

//calculates the final damage when player got hit.
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

//updates health
void player::changeHealth(abstractEvent* msgEvent)
{
	//cast
	changeHealthEvent& newHealth = *(changeHealthEvent*)msgEvent;

	health = newHealth.newHealth;
}

//updates stamina.
void player::changeStamina(abstractEvent* msgEvent)
{
	//cast
	changeStaminaEvent& newStamina = *(changeStaminaEvent*)msgEvent;

	stamina = newStamina.newStamina;
	//std::cout<<"changed stamina to: "<<stamina<<std::endl;
}

void player::getPlayerStats(abstractEvent* msgEvent)
{
	//cast
	getPlayerStatsEvent& getStats = *(getPlayerStatsEvent*)msgEvent;

	getStats.cHealth	=	health;
	getStats.mHealth	=	maxHealth;
	getStats.cStamina	=	stamina;
	getStats.mStamina	=	maxStamina;
	getStats.cMana		=	mana;
	getStats.mMana		=	maxMana;
}


#pragma endregion


#pragma region collision handlers

void player::collidedWith(gameObject& object)
{
	int objectType = object.objectType;

	if(objectType == sceneryT)
	{
		//std::cout<<"player collided with scenery"<<std::endl;
		messageBus::sharedMessageBus()->sendMessage(changeHealthEvent(health - frameRateLimiter::sharedFrameRateLimiter()->frameDelta * 1));
	}

}

#pragma endregion code related to effects of collisions