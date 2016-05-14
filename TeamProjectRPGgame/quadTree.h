#include <iostream>
#include <vector>
#include "gameObject.h"
#include "SDLManager.h"

//**quadTree is a tree structure with nodes that split into 4 more smaller nodes whenever they begin to contain more objects than a set value**//
//**this is going to be used to optimise our collision detection. Objects will only check collision against other objects contained in the same node**//
//**this is also a recursive implementation**//
class quadTree
{
protected:

	//node position//
	float	x;
	float	y;
	float	width;
	float	height;
	int		level;						//the depth of the current node.
	//------------//
	int		maxLevel;					//maximum depth of the tree structure.
	int		maxObjects;

	std::vector<gameObject*>* objects;	//list of the objects contained in this node.
	
	//child nodes//
	//quadTree* NW;	//north west node
	//quadTree* NE;	
	//quadTree* SW;	
	//quadTree* SE;	//south east node
	quadTree* childNodes[4];
	//-----------//

	void split();

	int getIndex(int _x, int _y, int _w, int _h);

	//contains function check if the object you are passing is within the bounds of the node you are passing, which in practice are going to be child nodes
	//bool	contains(quadTree *child, gameObject *object);

public:
	quadTree(float x, float y, float width, float height, int level, int maxLevel);
	~quadTree();

	void	addObject(gameObject *object);						//tries to add object to one of it's child nodes, if not possible adds one to this node.
	std::vector<gameObject*>* getObjectsAt(std::vector<gameObject*>& returnVector, float _x, float _y, float _w, float _h);
	//std::vector<gameObject*> getObjectsAt(float x, float y);	//returns list of objects from node located ad x,y
	void clear();												//clears the node, removes objects from the list.
	void draw();
};