#include "gameManager.h"

/*shared static instance of the gameManager class
this is the real pSharedGameManager object global*/
gameManager*	gameManager::pSharedGameManager = NULL;

gameManager::gameManager(void)
{

	std::cout<<std::endl<<"gameManager created... "<<std::endl;

	isRunning = true;
	gameState = TITLE;
	startTime = 0;

}

gameManager::~gameManager(void){}

gameManager* gameManager::sharedGameManager()
{	
	if(pSharedGameManager == NULL){pSharedGameManager = new gameManager();}
	return pSharedGameManager;
}

//--limiting of the framerate--//
void gameManager::regulateFrameRate()
{
	if(startTime - SDL_GetTicks() < 1000/FRAMERATE)
	{
		SDL_Delay((1000 / FRAMERATE) - (startTime - SDL_GetTicks()));
	}
	startTime = SDL_GetTicks();
}
//-----------------------------//


void gameManager::addToList(gameObject* tgo, int list)
{
	if(list == TITLE)	{ titleList.push_back(tgo);			}
	if(list == GAME)	{ gamePlayList.push_back(tgo);		}
	if(list == HELP)	{ helpList.push_back(tgo);			}
	if(list == GAMEOVER){ gameOverList.push_back(tgo);		}
	if(list == PAUSE)	{ pauseList.push_back(tgo);			}
}

void gameManager::updateList(int list)
{

	if(list == TITLE)	
	{ 
		for(int i = 0; i < titleList.size(); i++){ titleList[i]->update(); }	
	}
	if(list == GAME)
	{
		for(int i = 0; i < gamePlayList.size(); i++){ gamePlayList[i]->update(); }
	}
	if(list == HELP)
	{
		for(int i = 0; i < helpList.size(); i++){ helpList[i]->update(); }
	}
	if(list == GAMEOVER)
	{
		for(int i = 0; i < gameOverList.size(); i++){ gameOverList[i]->update(); }
	}
	if(list == PAUSE)
	{
		for(int i = 0; i < pauseList.size(); i++){ pauseList[i]->update(); }
	}

}

void gameManager::drawList(int list)
{

	if(list == TITLE)	
	{ 
		for(int i = 0; i < titleList.size(); i++){ titleList[i]->draw(); }	
	}
	if(list == GAME)
	{
		for(int i = 0; i < gamePlayList.size(); i++){ gamePlayList[i]->draw(); }
	}
	if(list == HELP)
	{
		for(int i = 0; i < helpList.size(); i++){ helpList[i]->draw(); }
	}
	if(list == GAMEOVER)
	{
		for(int i = 0; i < gameOverList.size(); i++){ gameOverList[i]->draw(); }
	}
	if(list == PAUSE)
	{
		for(int i = 0; i < pauseList.size(); i++){ pauseList[i]->draw(); }
	}

}


//--COLLISION CHECKS--//
bool gameManager::checkCollisionWith(std::string type, SDL_Rect &collisionBox)
{
	for (int i = 0; i < gamePlayList.size(); i++)
	{
		//checks if the object is the right type//
		if (gamePlayList[i]->objectType == type)
		{
			//checks each of the targets collision boxes
			for (int j = 0; j < gamePlayList[i]->collisionBoxes.size(); j++)
			{
				//checks the collision
				if (gamePlayList[i]->collisionWith(&collisionBox, gamePlayList[i]->collisionBoxes[j]))
				{

					return true;
				}
			}

		}
	}


	return false;
}


//sweep deletes any object that are no longer "alive" it does so at the very end of the frame in order to make sure that no deleted items get called.
void gameManager::sweep()
{
	for(int i=0; i<titleList.size();i++)
	{
		if(titleList.at(i)->getAlive() == false)	
		{
			delete titleList.at(i);
			titleList.erase(titleList.begin()+i);
		}
	}

	for(int i=0; i<helpList.size();i++)
	{
		if(helpList.at(i)->getAlive() == false)	
		{
			delete helpList.at(i);
			helpList.erase(helpList.begin()+i);
		}
	}

	for(int i=0; i<gamePlayList.size();i++)
	{
		if(gamePlayList.at(i)->getAlive() == false)	
		{
			delete gamePlayList.at(i);
			gamePlayList.erase(gamePlayList.begin()+i);
		}
	}

	for(int i=0; i<gameOverList.size();i++)
	{
		if(gameOverList.at(i)->getAlive() == false)	
		{
			delete gameOverList.at(i);
			gameOverList.erase(gameOverList.begin()+i);
		}
	}

	for(int i=0; i<pauseList.size();i++)
	{
		if(pauseList.at(i)->getAlive() == false)	
		{
			delete pauseList.at(i);
			pauseList.erase(pauseList.begin()+i);
		}
	}

}

void gameManager::freeMemory()
{


}

void gameManager::drawCollisionBoxes()
{

	for (int i = 0; i < gamePlayList.size(); i++)
	{
		gamePlayList.at(i)->drawCollisionBox();
	}

}