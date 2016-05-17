#include "consumePotionEvent.h"

consumePotionEvent::consumePotionEvent(int potion)
{
	potionName = potion;
	std::cout << "potion name was: " << potionName << std::endl;
}