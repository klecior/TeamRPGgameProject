#pragma once
#include "gameobject.h"
#include "textureImage.h"
#include "messageBus.h"
#include "constants.h"
#include "SpriteManager.h"
#include "gameManager.h"

//events//
#include "movePlayerEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include "hitPlayerEvent.h"
#include "changeHealthEvent.h"

class player :
	public gameObject
{
protected:

	void loadOnCreation();
	void handleMessage(abstractEvent& msgEvent);

	textureImage*	idleState;
	textureImage*	moveState;

	int health;
	int stamina;
	int mana;

	int totalDefenceTreshold;


	bool isMoving;

	//event handlers
	void playerMovement(abstractEvent* msgEvent);
	void onHit(abstractEvent* msgEvent);
	void changeHealth(abstractEvent* msgEvent);

public:
	player(void);
	~player(void);

	void update();

};



