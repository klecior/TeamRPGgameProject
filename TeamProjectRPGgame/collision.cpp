#include "collision.h"


bool collision::checkCollision(gameObject& object1, gameObject& object2)
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
