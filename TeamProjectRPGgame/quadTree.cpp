#include "quadTree.h"

quadTree::quadTree(float _x, float _y, float _width, float _height, int _level, int _maxLevel)
{

	x			=	_x;
	y			=	_y;
	width		=	_width;
	height		=	_height;
	level		=	_level;
	maxLevel	=	_maxLevel;
	maxObjects	=	10;
	if(level == maxLevel){return;}					//if the node is allready at the deepest possible level, quits the constructor preventing it from creating more nodes.

	const float halfWidth	=	width	/	2;		//width of the child nodes
	const float halfHeight	=	height	/	2;		//height of the child nodes

	//creates child nodes at gives them appropriate bounds
	//NW = new quadTree(x, y, halfWidth, halfHeight, level+1, maxLevel);
	//NE = new quadTree(x + halfWidth, y, halfWidth, halfHeight, level+1, maxLevel);
	//SW = new quadTree(x, y + halfHeight, halfWidth, halfHeight, level+1, maxLevel);
	//SE = new quadTree(x + halfWidth, y + halfHeight, halfWidth, halfHeight, level+1, maxLevel);
	childNodes[0] = NULL;
	childNodes[1] = NULL;
	childNodes[2] = NULL;
	childNodes[3] = NULL;
}

quadTree::~quadTree()
{
	if(level == maxLevel){ return; }	//if deepest node, quits constructor since there is node doesn't contain childs. Removing this if would make it crash as it would try to delete something that doesn't exist.

	//delete NW;
	//delete NE;
	//delete SW;
	//delete SE;
	delete childNodes;
}
/*
void quadTree::addObject(gameObject *object)
{
	//if allready at deepest node, can't create more children anyway so just adds object to this list.
	if(level == maxLevel)
	{
		objects.push_back(object);
		return;
	}

	//checks if any of the child nodes can accept the object
	if(contains(NW, object))
	{
		NW->addObject(object);
		return;
	}
	else if(contains(NE, object))
	{
		NE->addObject(object);
		return;
	}
		else if(contains(SW, object))
	{
		SW->addObject(object);
		return;
	}
		else if(contains(NE, object))
	{
		SE->addObject(object);
		return;
	}

	//if nonde of the child nodes can take it, checks if THIS node can. If it can't the parent node of this node will know that it can, and look for other place to put it.
	if(contains(this, object))
	{
		objects.push_back(object);
	}

}
*/
/*
void quadTree::addObject(gameObject *object)
{
	//if allready at deepest node, can't create more children anyway so just adds object to this list.
	if(level == maxLevel)
	{
		objects.push_back(object);
		return;
	}

	//if node has childs.
	if(childNodes[0] != NULL)
	{
	//checks if any of the child nodes can accept the object
		if(contains(childNodes[0], object))
		{
			childNodes[0]->addObject(object);
			return;
		}
		else if(contains(childNodes[1], object))
		{
			childNodes[1]->addObject(object);
			return;
		}
			else if(contains(childNodes[2], object))
		{
			childNodes[2]->addObject(object);
			return;
		}
			else if(contains(childNodes[3], object))
		{
			childNodes[3]->addObject(object);
			return;
		}
	}

	//if nonde of the child nodes can take it, checks if THIS node can. If it can't the parent node of this node will know that it can, and look for other place to put it.
	if(contains(this, object))
	{
		objects.push_back(object);
	}

	if(objects.size() > maxObjects && level < maxLevel)
	{
		if(childNodes[0] == NULL)
		{
			split();
		}

		int i = 0;
		while(i < objects.size())
		{
			int index = 
		}

	}

}
*/
/*
std::vector<gameObject*> quadTree::getObjectsAt(float _x, float _y)
{
	if(level == maxLevel){return objects;}			//if this is the last node, returns it's objects.

	std::vector<gameObject*> returnObjects, childReturnObjects;		//creates a vector list of object that it will return later, and a list of objects that this node will receive from it's childs.

	//if there are objects in here, return them.
	if(!objects.empty())
	{
		returnObjects = objects;
	}

	const float halfWidth = width /2;
	const float halfHeight = height /2;
	//TODO: in the example, it was halfWidth = height/2. I changed it to halfWidth = width / 2; since I think the example had a mistake, but keeping this node in case it was not a mistake.

	if(_x > x + halfWidth && _x < x + width)
	{
		if(_y > y + halfHeight && _y < y + height)
		{
			childReturnObjects = SE->getObjectsAt(_x, _y);
			returnObjects.insert(returnObjects.end(),childReturnObjects.begin(),childReturnObjects.end());
			return returnObjects;
		}
		else if(_y > y && _y <= y + halfHeight)
		{
			childReturnObjects = NE->getObjectsAt(_x, _y);
			returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
			return returnObjects;
		}
	}
	else if (_x > x && _x <= x + halfWidth) 
	{
		if (_y > y + halfHeight && _y < y + height) 
		{
			childReturnObjects = SW->getObjectsAt(_x, _y);
			returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
			return returnObjects;
		} 
		else if (_y > y && _y <= y + halfHeight) 
		{
			childReturnObjects = NW->getObjectsAt(_x, _y);
			returnObjects.insert(returnObjects.end(), childReturnObjects.begin(), childReturnObjects.end());
			return returnObjects;
		}
	}

	return returnObjects;
}

*/

void quadTree::clear()
{

	objects.clear();

	for(int i = 0; i < 4; i++)
	{
		if(childNodes[i] != NULL)
		{
			childNodes[i]->clear();
			childNodes[i] = NULL;
		}
	}
}

/*
bool quadTree::contains(quadTree *child, gameObject* object)
{
	//return false if any of the corners is out of bounds, returns true otherwise.
	return !(	object->getPosition().x < child->x	||
				object->getPosition().y < child->y	||
				object->getPosition().x > child->x + child->width	||
				object->getPosition().y > child->y + child->height	||
				object->getPosition().x + object->getPosition().w < child->x	||
				object->getPosition().y + object->getPosition().h < child->y	||
				object->getPosition().x + object->getPosition().w > child->x + child->width	||
				object->getPosition().y + object->getPosition().h > child->y + child->height);
		
}

*/

void quadTree::split()
{
	const float halfWidth	=	width	/	2;		//width of the child nodes
	const float halfHeight	=	height	/	2;		//height of the child nodes

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
		int index = getIndex(object->getPosition().x, object->getPosition().y, object->getPosition().w, object->getPosition().h);

		//if one of the childs can take it.
		if(index != -1)
		{
			childNodes[index]->addObject(object);
			return;		//quits the function
		}
	}

	//if none of the child nodes could take it, adds it to this one
	objects.push_back(object);

	//if the node now contains more than it can take, and it's not at the maximum depth
	if(objects.size() > maxObjects && level < maxLevel)
	{
		//if there is no children, create them.
		if(childNodes[0] == NULL){ split(); }
		
		int i = 0;
		//distribute all of this node objects onto the childs
		while(i < objects.size())
		{
			//checks which child can take this objct
			int index = getIndex(objects.at(i)->getPosition().x, objects.at(i)->getPosition().y, objects.at(i)->getPosition().w, objects.at(i)->getPosition().h);
	
			if(index != -1)
			{ 
				childNodes[index]->addObject(objects.at(i));
				objects.erase(objects.begin() + i);
			}
			else
			{
				i++;	//if no child can take it, node remains on this node, check another object.
			}
		}
	}
}

//gets all the items that can be hit by a box of these bounds
std::vector<gameObject*> quadTree::getObjectsAt(float _x, float _y, float _w, float _h)
{
	int index = getIndex(_x,_y,_w,_h);

	std::vector<gameObject*> returnVector;
	std::vector<gameObject*> childReturnVector;

	returnVector = objects;		//gets all of this node objects, in case not all of them could fit in the childs and had to remain here.

	if(index != -1 && childNodes[0] != NULL)
	{
		childReturnVector = childNodes[index]->getObjectsAt(_x,_y,_w,_h);			//gets the objects from the children node.
	}

	returnVector.insert(returnVector.end(),childReturnVector.begin(),childReturnVector.end());	//adds two of the vectors together.
	return returnVector;
}