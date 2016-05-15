#include "quadTree.h"

quadTree::quadTree(float _x, float _y, float _width, float _height, int _level, int _maxLevel)
{
	objects = new std::vector<gameObject*>;
	x			=	_x;
	y			=	_y;
	width		=	_width;
	height		=	_height;
	level		=	_level;
	maxLevel	=	_maxLevel;
	maxObjects	=	10;
	//TODO: maxObjects value may need tinkering to see what works best based on our average zone size. I left it at 5 for testing purposes.

	if(level == maxLevel){return;}					//if the node is allready at the deepest possible level, quits the constructor preventing it from creating more nodes.

	const float halfWidth	=	width	/	2;		//width of the child nodes
	const float halfHeight	=	height	/	2;		//height of the child nodes

	//creates empty child nodes, have them ready until they are needed.
	childNodes[0] = NULL;
	childNodes[1] = NULL;
	childNodes[2] = NULL;
	childNodes[3] = NULL;
}

quadTree::~quadTree()
{
	if(level == maxLevel){ return; }	//if deepest node, quits constructor since there is node doesn't contain childs. Removing this if would make it crash as it would try to delete something that doesn't exist.
	delete childNodes;
}

void quadTree::clear()
{

	objects->clear();

	for(int i = 0; i < 4; i++)
	{
		if(childNodes[i] != NULL)
		{
			childNodes[i]->clear();
			childNodes[i] = NULL;
		}
	}
}

void quadTree::split()
{
	const int halfWidth		=	width	/	2;		//width of the child nodes
	const int halfHeight	=	height	/	2;		//height of the child nodes

	childNodes[0] = new quadTree(x + halfWidth, y, halfWidth, halfHeight,level+1,maxLevel);
	childNodes[1] = new quadTree(x , y, halfWidth, halfHeight,level+1,maxLevel);
	childNodes[2] = new quadTree(x , y + halfHeight, halfWidth, halfHeight,level+1,maxLevel);
	childNodes[3] = new quadTree(x + halfWidth, y + halfHeight, halfWidth, halfHeight,level+1,maxLevel);


}

int quadTree::getIndex(int _x, int _y, int _w, int _h)
{
	int index = -1;

	double verticalMidpoint		= x + (width / 2);
	double horizontalMidpoint	= y + (height / 2);

	//if can fit in the top nodes
	bool topQuadrant	= (_y < horizontalMidpoint && _y + _h < horizontalMidpoint);
	//if can fit in bottom nodes
	bool bottomQuadran	= (_y > horizontalMidpoint);

	//if can fit in the left nodes
	if(_x < verticalMidpoint && _x + _w < verticalMidpoint)
	{
		if(topQuadrant)			{ index = 1; }
		else if(bottomQuadran)	{ index = 2; }
	}
	else if(_x > verticalMidpoint)
	{
		if(topQuadrant)			{ index = 0; }
		else if(bottomQuadran)	{ index = 3; }
	}

	return index;
}

void quadTree::addObject(gameObject* object)
{
	//if the node has childs, try adding to one of the childs.
	if(childNodes[0] != NULL)
	{
		//get the child that can take it.
		int index = getIndex(object->position.x, object->position.y, object->position.w, object->position.h);

		//if one of the childs can take it.
		if(index != -1)
		{
			childNodes[index]->addObject(object);
			return;		//quits the function
		}
	}

	//if none of the child nodes could take it, adds it to this one
	objects->push_back(object);

	//if the node now contains more than it can take, and it's not at the maximum depth
	if(objects->size() > maxObjects && level < maxLevel)
	{
		//if there is no children, create them.
		if(childNodes[0] == NULL)
		{ 
			split(); 
			int i = 0;
			//distribute all of this node objects onto the childs
			while(i < objects->size())
			{
				//checks which child can take this objct
				int index = getIndex(objects->at(i)->position.x, objects->at(i)->position.y, objects->at(i)->position.w, objects->at(i)->position.h);
	
				if(index != -1)
				{ 
					childNodes[index]->addObject(objects->at(i));
					objects->erase(objects->begin() + i);
				}
				else
				{
					i++;	//if no child can take it, node remains on this node, check another object.
				}
			}
		}
	}
}

//gets all the items that can be hit by a box of these bounds
std::vector<gameObject*>* quadTree::getObjectsAt(std::vector<gameObject*>& returnVector, float _x, float _y, float _w, float _h)
{
	int index = getIndex(_x,_y,_w,_h);

	//std::vector<gameObject*>* returnVector;
	std::vector<gameObject*>* childReturnVector = new std::vector<gameObject*>;

	//returnVector = *objects;		//gets all of this node objects, in case not all of them could fit in the childs and had to remain here.
	returnVector.insert(returnVector.end(),objects->begin(),objects->end());

	//if there are subnodes
	if(childNodes[0] != NULL)
	{
		//if fits into a subnode
		if(index != -1)
		{
			//childReturnVector = childNodes[index]->getObjectsAt(_x,_y,_w,_h);			//gets the objects from the children node.
			childNodes[index]->getObjectsAt(*childReturnVector,_x,_y,_w,_h);
			returnVector.insert(returnVector.end(),childReturnVector->begin(),childReturnVector->end());	//adds two of the vectors together.
		}//if doesn't fit in a subnode, check agains all nodes
		else
		{
			for(int i = 0; i < 4; i++)
			{
				childNodes[i]->getObjectsAt(*childReturnVector,_x,_y,_w,_h);
				returnVector.insert(returnVector.end(),childReturnVector->begin(),childReturnVector->end());	//adds two of the vectors together.
			}
		}

	}

	childReturnVector->clear();
	delete childReturnVector;


	return &returnVector;
}


void quadTree::draw()
{
	SDL_SetRenderDrawColor(SDLManager::sharedSDLManager()->mainRenderer, 0xBB,0xBB,0xBB,0xBB);

	SDL_Rect drawit;
	drawit.x = x;
	drawit.y = y;
	drawit.h = width;
	drawit.h = height;

	if(childNodes[0] == NULL)
	{
	

		SDL_RenderDrawRect(SDLManager::sharedSDLManager()->mainRenderer,&drawit);
		return;
	}

	for(int i = 0; i < 4; i++)
	{
		childNodes[i]->draw();
	}

	SDL_RenderDrawRect(SDLManager::sharedSDLManager()->mainRenderer,&drawit);

}