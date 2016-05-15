#pragma once
#include <SDL.h>
#include "observer.h"
#include <iostream>
#include "messageBus.h"
#include "constants.h"
#include "gameObject.h"

#include <vector>
#include <map>

#include "quadTree.h"
#include "collision.h"
#include "SDLManager.h"
//--events--//
#include "changeStateEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"


//**Collision sytem is responsible for keeping track of all objects with collisions, and performing the collision checks of the objects closests to each other**//
//**It is also informing the collided objects about their collision, and gives them the address of the object they collided with, allowing the objects themselves to decide what to do**//
class collisionSystem : public observer
{
protected:

	quadTree*	quad;											//quadTree takes the objects, and sets them into groups/zones/partitions based on location.

	std::vector<gameObject*> collideableObjectList;				//contains all of the objects with collisions.
	
	bool shouldDoCheckForThisObject(int type);			//returns true if it's important to check if this objects collides with anything, and false if it's not (for example, scenery never moves so it doesn't need to check if it collides with things. Other things such as player will still check if they collide with scenery.

	//event handlers
	void changeState(abstractEvent* msgEvent);
	void addToList(abstractEvent* msgEvent);
	void removeFromList(abstractEvent* msgEvent);

	void bruteForceCollision();
	void quadTreeCollision();

public:
	collisionSystem(void);
	~collisionSystem(void);
	
	void handleMessage(abstractEvent& msgEvent);

	void checkCollisions();
};

