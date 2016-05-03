#pragma once 

#include "gameObject.h"


class GUIbar : public gameObject
{
	private:
		
		textureImage* border;
		textureImage* bar;
		textureImage* backdrop;

		int percentageShown;
		SDL_Rect amountShown;
		SDL_Rect barPos;
	public:

		GUIbar();
		GUIbar(int percentage,std::string backDropPath,std::string barPath, std::string borderPath);
		void updatePercentage(int newPercentage);
		void draw();
};