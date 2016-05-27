#include "button.h"

button::button()
{
	std::cout<<"YOU CALLED THE WRONG BUTTON CONSTRUCTOR: you gave it no arguments, use (gameStateYouWant,image path1, image path2)"<<std::endl;
}

//--Creates a button with one, state containing temporary 'x' image--//
button::button(int list)
{
	position.x = 0;
	position.y = 0;
	loadImages("images/temp/X.png","images/temp/X.png");
	displayImage = sprIdle;

	objectType		=	GUIT;
	buttonClicked	=	false;
	hasCollision	=	false;
	alive			=	true;
	belongsToState	=	list;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(list,objectType,this));
	messageBus::sharedMessageBus()->registerListener(leftMouseClickMessage,this);
}

//--Creates a button and loads both of the states straight away. Lowers the amount of code required later--//
button::button(int list, std::string idle, std::string over)
{

	position.x = 0;
	position.y = 0;
	loadImages(idle,over);
	displayImage = sprIdle;

	objectType		=	GUIT;
	buttonClicked	=	false;
	hasCollision	=	false;
	alive			=	true;
	belongsToState	=	list;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(list,objectType,this));
	messageBus::sharedMessageBus()->registerListener(leftMouseClickMessage,this);
}


button::~button(void)
{
	sprIdle		 = NULL;
	sprOver		 = NULL;
	std::cout<<"button destroyer called"<<std::endl;
	messageBus::sharedMessageBus()->unRegisterListener(leftMouseClickMessage,this);
}


//--loads images for both states--//
void button::loadImages(std::string idle, std::string over)
{
	//--loads images--//
	//--images are loaded through the sprite manager, because it's more efficient this way--//
	sprIdle = assetManager::sharedAssetManager()->getImage(idle.c_str());
	sprOver = assetManager::sharedAssetManager()->getImage(over.c_str());
	//---------------//

	//--fills the width and height, used when centering the object--//
	position.w = sprIdle->getOffset().w;
	position.h = sprIdle->getOffset().h;
	//------------------------------------//

}

//--returns true or false depending on if the button was clicked--//
bool button::mouseClick()
{

	//--sets default sprite if there is no collision--//
	displayImage = sprIdle;
	hovering = false;
	

	if(buttonClicked == true)
	{
		buttonClicked = false;		//makes sure the button is not stuck in the permament state of being pressed.
		return true;				//returns that the button was clicked. This also quits the function.
	}

	//get mousePosition
	messageBus::sharedMessageBus()->sendMessage(currMousePos);

	//--x collision--//
	if(currMousePos.mouseXis > position.x && currMousePos.mouseXis < (position.x + position.w) )
		{
			//y collision--//
			if(currMousePos.mouseYis > position.y && currMousePos.mouseYis < (position.y +position.h) )
			{
				//--change the image to an different one--//
				displayImage = sprOver;
				hovering = true;
			}
		}
	//--if the mouse was not clicked on the button, return false--//
	return false;
}

void button::handleMessage(abstractEvent& msgEvent)
{
	int msgType = msgEvent.getEventType();

	if(msgType == leftMouseClickMessage)
	{
		if(hovering == true){ buttonClicked = true; }
	}
}
