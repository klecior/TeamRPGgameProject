#include "collision.h"

/*
bool checkCollision(gameObject& object1, gameObject& object2)
{
	//Checks every collision box of the first object against every collision box of the second object
	for (int i = 0; i < object1.collisionBoxes.size(); i++)
	{
		for (int j = 0; j < object2.collisionBoxes.size(); j++)
		{
			//collision on x//
			if (object1.collisionBoxes[i]->x > object2.collisionBoxes[j]->x && object1.collisionBoxes[i]->x < (object2.collisionBoxes[j]->x + object2.collisionBoxes[j]->w) || (object1.collisionBoxes[i]->x + object1.collisionBoxes[i]->w) > object2.collisionBoxes[j]->x && (object1.collisionBoxes[i]->x + object1.collisionBoxes[i]->w) < (object2.collisionBoxes[i]->x + object2.collisionBoxes[i]->w))
			{
				//collision on y//
				if (object1.collisionBoxes[i]->y > object2.collisionBoxes[j]->y && object1.collisionBoxes[i]->y < (object2.collisionBoxes[j]->y + object2.collisionBoxes[j]->h) || (object1.collisionBoxes[i]->y + object1.collisionBoxes[i]->h) > object2.collisionBoxes[j]->y && (object1.collisionBoxes[i]->y + object1.collisionBoxes[i]->h) < (object2.collisionBoxes[i]->y + object2.collisionBoxes[i]->h))
				{
					std::cout << "COLLISION" << std::endl;
					return true;
				}
			}
		}
	}
	return false;
}
*/

bool checkCollision(gameObject& object1, gameObject& object2)
{
	//If object 1 intersects object 2

	int x1 = object1.position.x;
	int y1 = object1.position.y;
	int w1 = object1.position.w;
	int h1 = object1.position.h;

	int x2 = object2.position.x;
	int y2 = object2.position.y;
	int w2 = object2.position.w;
	int h2 = object2.position.h;

	//collision on x//
	if (x1 > x2 && object1.position.x < (x2 + w2) || (x1 + w1) > x2 && (x1 + w1) < (x2 + w2))
	{
		//collision on y//
		if (y1 > y2 && y1 < (y2 + h2) || (y1 + h1) > y2 && (y1 + h1) < (y2 + h2))
		{
			//std::cout << "COLLISION with:"<<object2.objectType << std::endl;
			return true;
		}
	}

	return false;
}


/*
bool checkCollision(gameObject& object1, gameObject& object2)
{

	//collision on x//
	if (object1.
	.x < object2.getPosition().x + object2.getPosition().w && object1.getPosition().x + object1.getPosition().w > object2.getPosition().x)
	{
		if(object1.getPosition().y < object2.getPosition().y + object2.getPosition().h && object1.getPosition().h + object1.getPosition().y > object2.getPosition().y)
		{
			std::cout << "COLLISION with:"<<object2.objectType << std::endl;
			return true;
		}
	}
	return false;
}
*/
/*
bool checkCollision(gameObject& object1, gameObject& object2)
{
	int a_x = object1.getPosition().x / 2;
	int a_y = object1.getPosition().y / 2;
	int b_x = object2.getPosition().x / 2;
	int b_y = object2.getPosition().y / 2;
	//collision on x//
	if ( ( a_x - b_x) * 2 < ( object1.getPosition().w + object2.getPosition().w)	)
	{
		if(	 ( a_y - b_y ) * 2 < ( object1.getPosition().h + object2.getPosition().h)	)
		{
			std::cout << "COLLISION with:"<<object2.objectType << std::endl;
			return true;
		}
	}
	return false;
}*/