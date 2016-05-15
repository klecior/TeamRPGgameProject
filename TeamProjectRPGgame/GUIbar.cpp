#include "GUIbar.h"

//default bar with nothing to show.
GUIbar::GUIbar()
{
	std::cout<<"POSSIBLE ERROR: created generig GUI bar with no images"<<std::endl;
	percentageShown	=	100;
	bar				=	nullptr;
	border			=	nullptr;
	backdrop		=	nullptr;
	position.h		=	0;
	position.w		=	0;
	amountShown.x	=	0;
	amountShown.y	=	0;
	amountShown.w	=	position.w;
	amountShown.h	=	position.h;
	objectType		=	GUIT;
}

//GUI bar that accepts how much of it should be shown at the start, and all the paths to the images building it up.
GUIbar::GUIbar(int percentage,std::string backDropPath,std::string barPath, std::string borderPath)
{
	percentageShown	=	percentage;
	bar				=	AssetManager::sharedAssetManager()->getImage(barPath);
	border			=	AssetManager::sharedAssetManager()->getImage(borderPath);
	backdrop		=	AssetManager::sharedAssetManager()->getImage(backDropPath);
	position.h		=	bar->getOffset().h;
	position.w		=	bar->getOffset().w;
	amountShown.x	=	0;
	amountShown.y	=	0;
	amountShown.h	=	position.h;
	amountShown.w	=	0;
	objectType		=	GUIT;
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, objectType, this));
}

void GUIbar::draw()
{
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,backdrop->getTexture(),NULL,&position);
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,bar->getTexture(),&amountShown,&barPos);		//this render call avoids squashing the bar when it gets smaller, instead it just shows smaller portion of it.
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,border->getTexture(),NULL,&position);
}

//changes how much of the health bar is shown.
void GUIbar::updatePercentage(int newPercentage)
{

	percentageShown = newPercentage;
	amountShown.w	=	percentageShown * 2;	// *2 because the bar we are currently using is 200px wide. 
	
	// TODO: update this function if we ever use a gui bar of different size. Preferably make it adaptable.

	barPos		=	position;
	barPos.w	=	amountShown.w;
	
}