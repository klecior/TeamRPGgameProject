#pragma once
#include "gameobject.h"
#include "textureImage.h"
#include "messageBus.h"
#include "constants.h"
#include "SpriteManager.h"
#include "gameManager.h"
class player :
	public gameObject
{
protected:

	void loadOnCreation();
	void handleMessage(int message);

	textureImage*	idleState;
	textureImage*	moveState;

	bool isMoving;

public:
	player(void);
	~player(void);

	void update();
};



