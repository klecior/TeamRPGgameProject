#include "GUIbar.h"

GUIbar::GUIbar()
{
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
	objectType		= "GUI";
}

GUIbar::GUIbar(int percentage,std::string backDropPath,std::string barPath, std::string borderPath)
{
	percentageShown	=	percentage;
	bar				=	SpriteManager::sharedSpriteManager()->getImage(barPath);
	border			=	SpriteManager::sharedSpriteManager()->getImage(borderPath);
	backdrop		=	SpriteManager::sharedSpriteManager()->getImage(backDropPath);
	position.h		=	bar->getOffset().h;
	position.w		=	bar->getOffset().w;
	amountShown.x	=	0;
	amountShown.y	=	0;
	amountShown.h	=	30;
	objectType		= "GUI";
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, "GUI", this));
}

void GUIbar::draw()
{
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,backdrop->getTexture(),NULL,&position);
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,bar->getTexture(),&amountShown,&barPos);
	SDL_RenderCopy(SDLManager::sharedSDLManager()->mainRenderer,border->getTexture(),NULL,&position);
}

void GUIbar::updatePercentage(int newPercentage)
{

	percentageShown = newPercentage;
	amountShown.w	=	percentageShown * 2;

	barPos		= position;
	barPos.w	=	amountShown.w;
	
}