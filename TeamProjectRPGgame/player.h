#pragma once
#include "gameobject.h"
#include "textureImage.h"
#include "messageBus.h"
#include "constants.h"
#include "AssetManager.h"
#include "gameManager.h"
#include "statusEffect.h"

#include "frameRateLimiter.h"

//events//
#include "playerControlsEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include "hitPlayerEvent.h"
#include "changeHealthEvent.h"
#include "changeStaminaEvent.h"
#include "getPlayerStatsEvent.h"
#include "leftMouseClickEvent.h"
#include "castSpellEvent.h"
#include "addStatusEffectEvent.h"

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

	//movement//
	float	baseSpeed;
	float	movementSpeed;
	float	sprintModifier;
	float	sprintCost;
	bool	isSprinting;
	bool	teleportReady;

	bool isMoving;
	void sprint();
	void walk(playerControlsEvent* controls);
	void staminaRegen();
	//-----//

	//std::vector<statusEffect> statusEffectQueue;

	int totalDefenceTreshold;

	void handleSprites();

	//event handlers
	void playerControls(abstractEvent* msgEvent);
	void onHit(abstractEvent* msgEvent);
	void changeHealth(abstractEvent* msgEvent);
	void changeStamina(abstractEvent* msgEvent);
	void getPlayerStats(abstractEvent* msgEvent);
	void spellHandler(abstractEvent* msgEvent);

	//spells
	void teleport(abstractEvent* msgEvent);

public:
	player(void);
	~player(void);

	void update();

	void collidedWith(gameObject& object);

};



