#include "inputSystem.h"


inputSystem::inputSystem(void)
{
	upKey		= false;
	downKey		= false;
	leftKey		= false;
	rightKey	= false;
	spaceKey	= false;
	escKey		= false;

	mouseX		=	0;
	mouseY		=	0;
	
	currentStateE.eventID = getCurrentGameState;
	messageBus::sharedMessageBus()->registerSystem(this);

	//temp debug keys//
	uKey	=	false;
	iKey	=	false;
	oKey	=	false;
	jKey	=	false;
	kKey	=	false;
	lKey	=	false;

}


inputSystem::~inputSystem(void)
{
	
}

//interface with the rest of the program.
void inputSystem::manageInput(SDL_Event &evt)
{
	while(SDL_PollEvent(&evt))
	{
		manageKeyHolds(evt);
		handleMouse(evt);
	}
	translateMeaning();
}

//allows for holding of multiple keys at once.
void inputSystem::manageKeyHolds(SDL_Event &evt)
{

		if(evt.type == SDL_KEYDOWN)
		{
			if(evt.key.keysym.sym == SDLK_RIGHT || evt.key.keysym.sym == SDLK_d){rightKey	= true;	}
			if(evt.key.keysym.sym == SDLK_LEFT  || evt.key.keysym.sym == SDLK_a){leftKey	= true;	}
			if(evt.key.keysym.sym == SDLK_UP    || evt.key.keysym.sym == SDLK_w){upKey		= true;	}
			if(evt.key.keysym.sym == SDLK_DOWN  || evt.key.keysym.sym == SDLK_s){downKey	= true;	}
			if(evt.key.keysym.sym == SDLK_ESCAPE|| evt.key.keysym.sym == SDLK_p){escKey		= true;	}

			if(evt.key.keysym.sym == SDLK_SPACE){spaceKey = true;}

			//debug
			if(evt.key.keysym.sym == SDLK_u){uKey	= true;	}
			if(evt.key.keysym.sym == SDLK_i){iKey	= true;	}
			if(evt.key.keysym.sym == SDLK_o){oKey	= true;	}
			if(evt.key.keysym.sym == SDLK_j){jKey	= true;	}
			if(evt.key.keysym.sym == SDLK_k){kKey	= true;	}
			if(evt.key.keysym.sym == SDLK_l){lKey	= true;	}

		}

		if(evt.type == SDL_KEYUP)
		{
			if(evt.key.keysym.sym == SDLK_RIGHT || evt.key.keysym.sym == SDLK_d){rightKey	= false;	}
			if(evt.key.keysym.sym == SDLK_LEFT  || evt.key.keysym.sym == SDLK_a){leftKey	= false;	}
			if(evt.key.keysym.sym == SDLK_UP    || evt.key.keysym.sym == SDLK_w){upKey		= false;	}
			if(evt.key.keysym.sym == SDLK_DOWN  || evt.key.keysym.sym == SDLK_s){downKey	= false;	}				
			if(evt.key.keysym.sym == SDLK_ESCAPE|| evt.key.keysym.sym == SDLK_p){escKey		= false;	}

			if(evt.key.keysym.sym == SDLK_SPACE){spaceKey = false;	}

			//debug
			if(evt.key.keysym.sym == SDLK_u){uKey	= false;	}
			if(evt.key.keysym.sym == SDLK_i){iKey	= false;	}
			if(evt.key.keysym.sym == SDLK_o){oKey	= false;	}
			if(evt.key.keysym.sym == SDLK_j){jKey	= false;	}
			if(evt.key.keysym.sym == SDLK_k){kKey	= false;	}
			if(evt.key.keysym.sym == SDLK_l){lKey	= false;	}

		}
		if(evt.type == SDL_QUIT){ messageBus::sharedMessageBus()->sendMessageS(quitGame); }
		
}

//--handling of the mouse events--//
void inputSystem::handleMouse(SDL_Event& evt)
{
	mouseX = evt.button.x;
	mouseY = evt.button.y;

	if(evt.type == SDL_MOUSEBUTTONDOWN && evt.button.button == SDL_BUTTON_LEFT)
	{
		messageBus::sharedMessageBus()->sendMessageS(leftMouseClick);
		messageBus::sharedMessageBus()->sendMessageO(leftMouseClick);
	}

}
//---------------------------------//


void inputSystem::translateMeaning()
{
	messageBus::sharedMessageBus()->sendMessageS(currentStateE);

	if(currentStateE.intData == GAME)	{ gameplayInputs(); }
	else
	{
		menuInputs();
	}



	//debug stuff
	if(kKey){ messageBus::sharedMessageBus()->sendMessageS(msgEvent(healthChange,30,false)); }
	
}

void inputSystem::gameplayInputs()
{
	if(upKey)	{	messageBus::sharedMessageBus()->sendMessageO(movePup);		}
	if(downKey)	{	messageBus::sharedMessageBus()->sendMessageO(movePdown);	}
	if(leftKey)	{	messageBus::sharedMessageBus()->sendMessageO(movePleft);	}
	if(rightKey){	messageBus::sharedMessageBus()->sendMessageO(movePright);	}
}

void inputSystem::menuInputs()
{

}

void inputSystem::handleMessage(int message)
{
	
}
void inputSystem::handleMessage(msgEvent& msg)
{
	if(msg.eventID == getMouseX){msg.intData = mouseX;	}
	if(msg.eventID == getMouseY){msg.intData = mouseY; }
}
