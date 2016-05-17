#pragma once
#include "gameObject.h"
#include "messageBus.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include <iostream>

class genericCollider : public gameObject
{
protected:

	std::vector<gameObject*>*collidedList;

public:
	genericCollider(int state,int x, int y, int w, int h);

	genericCollider(int state, SDL_Rect collisionBounds);

	~genericCollider();

	int atState;

	void collidedWith(gameObject& object);

	std::vector<gameObject*>*gameCollisions();
	void clearList();
	//notice me git sempai
};