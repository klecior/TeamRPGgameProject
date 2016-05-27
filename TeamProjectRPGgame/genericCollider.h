#pragma once
#include "gameObject.h"
#include "messageBus.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include <iostream>
/* Class Name: generic Collider
Author:Andrija Delevic
The purpose of this class is to check if there is any collision occuring
within a certain area of the object it's attached to.
It has two constructors, one for taking x,y,width and height, the other takes SDL_Rectangle.
*/


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
	void move(int x, int y);
	void draw();

	std::vector<gameObject*>*gameCollisions();
	void clearList();
};