#pragma once 

#include "gameObject.h"
#include "messageBus.h"
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"

//**GUIbar is a generic GUI object that can be used for display of all sort of information that can be represented through a bar.**//
//**in our case, the most common usage is going to be health, stamina, and mana. **//
class GUIbar : public gameObject
{
	private:
		
		//sprites that build up the bar//
		textureImage* border;
		textureImage* bar;
		textureImage* backdrop;
		//-----------------------------//
		
		int percentageShown;
		SDL_Rect amountShown;
		SDL_Rect barPos;
	public:

		GUIbar();
		GUIbar(int percentage,std::string backDropPath,std::string barPath, std::string borderPath);
		void updatePercentage(int newPercentage);
		void draw();
};