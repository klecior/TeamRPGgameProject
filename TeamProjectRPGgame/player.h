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

class player :
	public gameObject
{
protected:

	void loadOnCreation();
	void handleMessage(abstractEvent& msgEvent);

	textureImage*	idleState;
	textureImage*	moveState;

	bool isMoving;

	//event handlers
	void playerMovement(abstractEvent* msgEvent);

public:
	player(void);
	~player(void);

	void update();

};



