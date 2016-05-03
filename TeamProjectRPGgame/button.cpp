#include "button.h"

//--Creates a button with one, state containing temporary 'x' image--//
button::button(int list)
{

	sprIdle = SpriteManager::sharedSpriteManager()->getImage("images/temp/X.png");
	displayImage = sprIdle;

	position.x = 0;
	position.y = 0;
	position.w = 0;
	position.h = 0;
	buttonClicked = false;

	getMouseXe.eventID = getMouseX;
	getMouseYe.eventID = getMouseY;
	gameManager::sharedGameManager()->addToList(this,list);
	messageBus::sharedMessageBus()->registerObject(this);
}

//--Creates a button and loads both of the states straight away. Lowers the amount of code required later--//
button::button(int list, std::string idle, std::string over)
{

	sprIdle = SpriteManager::sharedSpriteManager()->getImage(idle.c_str());
	sprOver = SpriteManager::sharedSpriteManager()->getImage(over.c_str());

	displayImage = sprIdle;

	position.x = 0;
	position.y = 0;
	position.w = sprIdle->getOffset().w;
	position.h = sprIdle->getOffset().h;
	buttonClicked = false;

	getMouseXe.eventID = getMouseX;
	getMouseYe.eventID = getMouseY;

	gameManager::sharedGameManager()->addToList(this,list);
	messageBus::sharedMessageBus()->registerObject(this);
}


button::~button(void)
{
	displayImage = NULL;
	sprIdle		 = NULL;
	sprOver		 = NULL;
}


//--loads images for both states--//
void button::loadImages(std::string idle, std::string over)
{
	//--loads images--//
	//--images are loaded through the sprite manager, because it's more efficient this way--//
	sprIdle = SpriteManager::sharedSpriteManager()->getImage(idle.c_str());
	sprOver = SpriteManager::sharedSpriteManager()->getImage(over.c_str());
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
		return true;				//returns that the button was clicked.
	}

	//--x collision--//
	messageBus::sharedMessageBus()->sendMessageS(getMouseXe);	//getX
	if(getMouseXe.intData > getPosition().x && getMouseXe.intData < (getPosition().x + getPosition().w) )
		{
			//y collision--//
			messageBus::sharedMessageBus()->sendMessageS(getMouseYe);	//getY
			if(getMouseYe.intData > getPosition().y && getMouseYe.intData < (getPosition().y +getPosition().h) )
			{
				//--change the image to an different one--//
				displayImage = sprOver;
				hovering = true;
			}
		}
	//--if the mouse was not clicked on the button, return false--//
	return false;
}

void button::handleMessage(int msg)
{
	if(msg == leftMouseClick)
	{
		if(hovering == true){ buttonClicked = true; }
	}
}
