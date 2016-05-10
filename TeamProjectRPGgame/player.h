#pragma once
#include "gameobject.h"
#include "textureImage.h"
#include "messageBus.h"
#include "constants.h"
#include "assetManager.h"
#include "gameManager.h"
#include "statusEffect.h"

//events//
#include "playerControlsEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include "hitPlayerEvent.h"
#include "changeHealthEvent.h"
#include "changeStaminaEvent.h"
#include "getPlayerStatsEvent.h"

class player :
	public gameObject
{
protected:

	void loadOnCreation();
	void handleMessage(abstractEvent& msgEvent);

	textureImage*	idleState;
	textureImage*	moveState;

#pragma region stats
	//vitals//
	float health;
	float maxHealth;

	float stamina;
	float maxStamina;

	float mana;
	float maxMana;

	float manaRecovery;
	float staminaRecovery;
	float healthRecovery;
	//------//
#pragma endregion player stats

	//speed//
	float	baseSpeed;
	float	movementSpeed;
	float	sprintModifier;
	float	sprintCost;
	bool	isSprinting;
	
	void staminaRegen();
	//-----//

	std::vector<statusEffect> statusEffectQueue;

	int totalDefenceTreshold;


	

	void handleSprites();

	//movement//
	bool isMoving;

	void sprint();
	void walk(playerControlsEvent* controls);
	//-------//

	//event handlers
	void playerControls(abstractEvent* msgEvent);
	void onHit(abstractEvent* msgEvent);
	void changeHealth(abstractEvent* msgEvent);
	void changeStamina(abstractEvent* msgEvent);
	void getPlayerStats(abstractEvent* msgEvent);

public:
	player(void);
	~player(void);

	void update();

};



