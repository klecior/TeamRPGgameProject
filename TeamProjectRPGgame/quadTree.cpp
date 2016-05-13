#include "quadTree.h"

quadTree::quadTree(float _x, float _y, float _width, float _height, int _level, int _maxLevel)
{

	x			=	_x;
	y			=	_y;
	width		=	_width;
	height		=	_height;
	level		=	_level;
	maxLevel	=	_maxLevel;

	if(level == maxLevel){return;}					//if the node is allready at the deepest possible level, quits the constructor preventing it from creating more nodes.

	const float halfWidth	=	width	/	2;		//width of the child nodes
	const float halfHeight	=	height	/	2;		//height of the child nodes

	//creates child nodes at gives them appropriate bounds
	NW = new quadTree(x, y, halfWidth, halfHeight, level+1, maxLevel);
	NE = new quadTree(x + halfWidth, y, halfWidth, halfHeight, level+1, maxLevel);
	SW = new quadTree(x, y + halfHeight, halfWidth, halfHeight, level+1, maxLevel);
	SE = new quadTree(x + halfWidth, y + halfHeight, halfWidth, halfHeight, level+1, maxLevel);

}

quadTree::~quadTree()
{
	if(level == maxLevel){ return; }	//if deepest node, quits constructor since there is node doesn't contain childs. Removing this if would make it crash as it would try to delete something that doesn't exist.

	delete NW;
	delete NE;
	delete SW;
	delete SE;
}

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


void quadTree::clear()
{
	if(level == maxLevel)
	{
		objects.clear();
		return;
	}
	else
	{
		NW->clear();
		NE->clear();
		SW->clear();
		SE->clear();
	}

	if(!objects.empty())
	{
		objects.clear();
	}
}


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