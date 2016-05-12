#pragma once
#include "gameobject.h"
#include <SDL.h>
#include <string>
#include "AssetManager.h"
#include "messageBus.h"

//events//
#include "getMousePosEvent.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"

 /**Button that returns "true" if clicked, contains 2 states: idle, and over.**/
class button :
	public gameObject
{
protected:

	//--images for the button to display--//
	textureImage* sprIdle;
	textureImage* sprOver;

	//--messages that need to be sent every frame--//
	getMousePosEvent currMousePos;
	//---------------------------------------------//

	bool hovering;
	bool buttonClicked;

public:
	button();														//does nothing other than give error message, was needed for something that inherits from button to shut up.
	button(int list);												//creates button with temporary 'X' image as both states.
	button(int list, std::string idle, std::string over);			//creates button with given graphics.
	~button(void);

	void loadImages(std::string idle, std::string over);			//loads images for both states of the button.
	void handleMessage(abstractEvent& msgEvent);					//button listens to some messages such as "getMousePos".


	bool mouseClick();												//returns true of false depending if the mouse was clicked.
};

