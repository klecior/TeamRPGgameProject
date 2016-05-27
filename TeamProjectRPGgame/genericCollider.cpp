#include "genericCollider.h"

genericCollider::genericCollider(int state,int x, int y, int w, int h)
{
	position.x = x;
	position.y = y;
	position.w = w;
	position.h = h;

	objectType = genericColliderT;
	collisionBox = position;

	hasCollision = true;
	atState = state;
	changeImage(assetManager::sharedAssetManager()->getImage("nothing,testing"));
	collidedList = new std::vector<gameObject*>;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(state, objectType, this));
}

genericCollider::genericCollider(int state,SDL_Rect collisionBounds)
{
	position = collisionBounds;
	objectType = genericColliderT;

	hasCollision = true;
	collisionBox = position;
	atState = state;
	

	collidedList = new std::vector<gameObject*>;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(state, objectType, this));

}

genericCollider::~genericCollider() 
{
	clearList();
	messageBus::sharedMessageBus()->sendMessage(entityDeletedEvent(atState, this));
	
}

void genericCollider::clearList()
{
	collidedList->clear();

}

void genericCollider::collidedWith(gameObject& object)
{
	collidedList->push_back(&object);

}

std::vector<gameObject*>*genericCollider::gameCollisions()
{
	return collidedList;
}

void genericCollider::move(int x, int y)
{
	position.x = x;
	position.y = y;
	collisionBox = position;
}

void genericCollider::draw()
{
	SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xBB,0xBB,0xFF,0xFF);
	SDL_RenderDrawRect(SDLManager::sharedSDLManager()->mainRenderer,&position);
	SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer,0xFF,0xFF,0xFF,0xFF);
}