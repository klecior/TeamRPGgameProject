#include "AssetManager.h"


/*shared static instance of the AssetManager class
this is the real pSharedAssetManager object global*/
assetManager*	assetManager::pSharedAssetManager = NULL;


assetManager::assetManager(void)
{
}


assetManager* assetManager::sharedAssetManager()
{	
	if(pSharedAssetManager == NULL){pSharedAssetManager = new assetManager();}
	return pSharedAssetManager;
}


//--checks if the image was allready loaded, if yes returns the loaded image, if no, makes one, puts it onto a list, and then returns it--//
textureImage*	assetManager::getImage(std::string path)
{
	
	//checks all the ids.
	for(int i = 0; i < idPngList.size(); i++)
	{

		//idExists.
		if(path == idPngList[i]->name)
		{
			//return the image on the that list.
			return imageList[idPngList[i]->id];
		}

	}

	//if it doesn't return anything after the loop, it doesn't exist. Create one.

	//create image.
	tempImage	=	new textureImage();
	tempImage->loadTexture(path);
	imageList.push_back(tempImage);

	//create ID.
	tempID			=	new idStruct();
	tempID->id		=	imageList.size() - 1;
	tempID->name	=	path;
	idPngList.push_back(tempID);

	//return the new image.
	return imageList[tempID->id];
}

//--checks if the animation was allready loaded, if yes returns the loaded animation, if no, makes one, puts it onto a list, and then returns it--//
sequenceAnimation* assetManager::getAnimation(unsigned int frames, std::string path)
{

	//checks all the ids.
	for(int i = 0; i < idAnimList.size(); i++)
	{

		//idExists.
		if(path == idAnimList[i]->name)
		{
			//return the animation on the that list.
			return animationList[idAnimList[i]->id];
		}

	}

	//if it doesn't return anything after the loop, it doesn't exist. Create one.

	//create animation.
	tempAnimation	=	new sequenceAnimation();
	tempAnimation->loadSequence(frames,path);
	animationList.push_back(tempAnimation);

	//create ID.
	tempID			=	new idStruct();
	tempID->id		=	animationList.size() - 1;
	tempID->name	=	path;
	idAnimList.push_back(tempID);

	//return the new image.
	return animationList[tempID->id];

}

Mix_Chunk* assetManager::getChunk(std::string path)
{
	
	//checks ids within list
	for (int i = 0; i < idChunkList.size(); i++)
	{
		//id exists
		if (path == idChunkList[i]->name)
		{
			//return the chunk that is already loaded
			return chunkList[idChunkList[i]->id];
		}

	}

	//loads new chunks if file was not found in list

	//creates audio chunk
	tempChunk	=	Mix_LoadWAV(path.c_str());
	chunkList.push_back(tempChunk);

	//create ID
	tempID = new idStruct();
	tempID->id = chunkList.size() - 1;
	tempID->name = path;
	idChunkList.push_back(tempID);

	return chunkList[tempID->id];
}

Mix_Music* assetManager::getMusic(std::string path)
{

	//checks ids within list
	for (int i = 0; i < idMusicList.size(); i++)
	{
		//id exists
		if (path == idChunkList[i]->name)
		{
			//return the music that is already loaded
			return musicList[idMusicList[i]->id];
		}

	}

	//loads new music if music was not found in the list

	//create music
	tempMusic	=	Mix_LoadMUS(path.c_str());
	musicList.push_back(tempMusic);

	//create ID
	tempID	=	new idStruct();
	tempID->id	=	musicList.size() - 1;
	tempID->name	=	path;
	idChunkList.push_back(tempID);

	return musicList[tempID->id];
}

//--InitializeFromFile function opens up a text document with every image and animation in the game, and then loads the graphics into memory, so it can be easily retrieved later--//
void assetManager::initializeFromFile(std::string path)
{
	//opens the file
	file.open(path.c_str(), std::ios::in);		

	//keeps going for every line of the files.
	while (!file.eof())												
	{
		//gets next line.
		getline(file, StringForStuff);											

		//--if the line is an image path--//
		if (StringForStuff[0] == 'i')				
		{

			//get the path//
			stringConverter << StringForStuff;																			
			stringConverter >> tempChar>> filePath;

			//load and push the image//
			tempImage = new textureImage();
			tempImage->loadTexture(filePath.c_str());
			imageList.push_back(tempImage);

			//load and push the id//
			tempID			=	new idStruct();
			tempID->id		=	imageList.size() - 1;
			tempID->name	=	filePath;
			idPngList.push_back(tempID);

			//clear variables//
			filePath.clear();
			stringConverter.clear();																		
														
		}
		
		//-- if the line is an animation path--//
		if (StringForStuff[0] == 'a')				
		{

			//get the path//
			stringConverter<<StringForStuff;
			stringConverter>>tempChar>>filePath>>framesAmount;

			//load and push the animation//
			tempAnimation	=	new sequenceAnimation();
			tempAnimation->loadSequence(framesAmount,filePath);
			animationList.push_back(tempAnimation);

			//load and push the id//
			tempID			=	new idStruct();
			tempID->id		=	animationList.size() - 1;
			tempID->name	=	filePath;
			idAnimList.push_back(tempID);

			//clear variables//
			filePath.clear();
			stringConverter.clear();	

		}

	}

	file.clear();								
	file.seekg(0);		
	file.close();

}

//--free memory will make sure that all of the lists are being properly cleared on quit--// //--Could be potentialy used in between loading screens if multiple levels with multiple graphics are being loaded--//
void assetManager::freeMemory()
{

	for(unsigned int i = 0;  i < imageList.size(); i++)
	{
		delete imageList[i];
		imageList[i] = NULL;
	}
	imageList.clear();
	
	for(unsigned int i = 0;  i < animationList.size(); i++)
	{
		delete animationList[i];
		animationList[i] = NULL;
	}
	animationList.clear();

	for(unsigned int i = 0; i < idPngList.size(); i++)
	{
		delete idPngList[i];
		idPngList[i] = NULL;
	}
	idPngList.clear();

	for(unsigned int i = 0; i < idAnimList.size(); i++)
	{
		delete idAnimList[i];
		idAnimList[i] = NULL;
	}
	idAnimList.clear();
	
	tempID			= NULL;
	tempImage		= NULL;
	tempAnimation	= NULL;
	

}