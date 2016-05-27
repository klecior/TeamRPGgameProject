#include "sceneryObject.h"


sceneryObject::sceneryObject(int atState, bool solid, std::string imagePath, int x, int y)
{
	belongsToState	=	atState;
	hasCollision	=	solid;
	objectImage		=	assetManager::sharedAssetManager()->getImage(imagePath);
	isAnimated		=	false;
	onFrame			=	0;

	position.x		=	x;
	position.y		=	y;
	position.w		=	objectImage->getOffset().w;
	position.h		=	objectImage->getOffset().h;

	changeImage(objectImage);

	collisionBox	= position;

	objectType		=	sceneryT;

	messageBus::sharedMessageBus()->registerListener(moveWorldMessage,this);
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(atState,objectType,this));
}

sceneryObject::sceneryObject(int atState, bool solid, bool animated, int frames, std::string animationPath, int x, int y)
{
	belongsToState	=	atState;
	hasCollision	=	solid;
	objectAnimation	=	assetManager::sharedAssetManager()->getAnimation(frames,animationPath);

	onFrame			=	0;

	position.x		=	x;
	position.y		=	y;
	position.w		=	objectAnimation->getFrame(onFrame)->getOffset().w;
	position.h		=	objectAnimation->getFrame(onFrame)->getOffset().h;

	changeImage(objectAnimation->getFrame(0));

	collisionBox	= position;

	objectType		=	sceneryT;

	messageBus::sharedMessageBus()->registerListener(moveWorldMessage,this);
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(atState,objectType,this));
}

sceneryObject::~sceneryObject()
{
	messageBus::sharedMessageBus()->unRegisterListener(moveWorldMessage,this);
}


void sceneryObject::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == moveWorldMessage){ moveWorldObject(&msgEvent); }
}

void sceneryObject::collidedWith(gameObject* object)
{

	if(object->objectType == playerT){std::cout<<"scenery is coliding with player"<<std::endl; }
}


void sceneryObject::update()
{
	if(isAnimated)
	{
		changeImage(objectAnimation->getFrame(onFrame));

		onFrame++;
		if(onFrame >= objectAnimation->framesAmount)
		{
			onFrame = 0;
		}
	}
}