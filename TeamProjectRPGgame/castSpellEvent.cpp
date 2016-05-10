#include "castSpellEvent.h"

castSpellEvent::castSpellEvent(int spell)
{
	spellName = spell;
	std::cout<<"spell name was: " << spellName << std::endl;
}