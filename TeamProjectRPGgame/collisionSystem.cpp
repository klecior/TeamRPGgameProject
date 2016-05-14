#include "collisionSystem.h"

collisionSystem::collisionSystem()
{
	//create a quadTree covering the screen.
	//quad = new quadTree(0,0,2048,2048,0,5);
	quad = new quadTree(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,0,5);
	messageBus::sharedMessageBus()->registerListener(entityCreatedMessage,this);
	messageBus::sharedMessageBus()->registerListener(entityDeletedMessage,this);
}


void collisionSystem::checkCollisions()
{
	/*
#pragma region collision checks through quadTree
	quad->clear();				//empties the quad tree every frame.

	//place all of the objects in the scene onto the quadTree, algorithm inside the tree will decide how to place them.
	for(int i = 0; i < collideableObjectList.size(); i++)
	{
		quad->addObject(collideableObjectList.at(i) );
	}

	quad->draw();

	std::vector<gameObject*>* returnObjects = new std::vector<gameObject*>;		
	for(int i = 0; i < collideableObjectList.size(); i++)
	{
		
		
		//if it's something that should do it's own checks
		if(shouldDoCheckForThisObject(collideableObjectList.at(i)->objectType))
		{
			returnObjects->clear();
			//returnObjects = quad->getObjectsAt(collideableObjectList.at(i)->getPosition().x, collideableObjectList.at(i)->getPosition().y, collideableObjectList.at(i)->getPosition().w, collideableObjectList.at(i)->getPosition().h);	//gets a list of all the objects that are located in the same zone as the currently checked object.
			quad->getObjectsAt(*returnObjects,collideableObjectList.at(i)->getPosition().x, collideableObjectList.at(i)->getPosition().y, collideableObjectList.at(i)->getPosition().w, collideableObjectList.at(i)->getPosition().h);	//gets a list of all the objects that are located in the same zone as the currently checked object.

			if(collideableObjectList.at(i)->objectType == "player")
			{
				static int timer = 0;
				if(timer >= 300)
				{
					std::cout<<"checking player agains: "<<returnObjects->size()<<" objects"<<std::endl;
					timer = 0;
				}
				else{ timer++;}
			}

			//check the collision against every object that is close enough.
			for(int j = 0; j <returnObjects->size(); j++)
			{
				//std::cout<<"checking against "<<returnObjects.size()<<" objects"<<std::endl;
				if(checkCollision(*collideableObjectList.at(i),*returnObjects->at(j) ) )
				{
					//inform objects that they collided, and give adresses of objects they collided with.
					collideableObjectList.at(i)->collidedWith(*returnObjects->at(j) );
					returnObjects->at(j)->collidedWith(*collideableObjectList.at(i) );

				}
			}
		}
	}
	returnObjects->clear();
	delete returnObjects;
#pragma endregion 
*/
	
#pragma region collisions check using brute force

	for(int i = 0; i < collideableObjectList.size(); i++)
	{
		for(int j = 0; j < collideableObjectList.size(); j++)
		{
			if(checkCollision(*collideableObjectList.at(i),*collideableObjectList.at(j) ) )
				{
					//inform objects that they collided, and give adresses of objects they collided with.
					collideableObjectList.at(i)->collidedWith(*collideableObjectList.at(j) );
					collideableObjectList.at(j)->collidedWith(*collideableObjectList.at(i) );
				}
		}
	}
#pragma endregion
	
}

void collisionSystem::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == entityCreatedMessage){ addToList(&msgEvent); }
	if(msgType == entityDeletedMessage){ removeFromList(&msgEvent); }
}

void collisionSystem::addToList(abstractEvent* msgEvent)
{
	//cast
	entityCreatedEvent& newEntity = *(entityCreatedEvent*)msgEvent;

	if(newEntity.createdObject->hasCollision)
	{
		collideableObjectList.push_back(newEntity.createdObject);
	}
}

void collisionSystem::removeFromList(abstractEvent* msgEvent)
{
	//cast
	entityDeletedEvent& delEntity = *(entityDeletedEvent*)msgEvent;

	//if it's something that would be here
	if(delEntity.deletedObject->hasCollision)
	{
		//find it
		for(int i = 0; i < collideableObjectList.size(); i++)
		{
			//if it matches, delete it.
			if(collideableObjectList.at(i) == delEntity.deletedObject)
			{
				collideableObjectList.erase(collideableObjectList.begin()+i);
			}
		}
	}
}


bool collisionSystem::shouldDoCheckForThisObject(std::string type)
{
	bool should = true;
	return true;
	if(type == "scenery")	{ should = false; }
	if(type == "tile")		{ should = false; }

	return should;
}
