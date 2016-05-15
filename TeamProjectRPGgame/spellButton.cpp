#include "spellButton.h"



spellButton::spellButton(std::string path1, std::string path2, int spellName)
{
	loadImages(path1, path2);
	sName = spellName;

	displayImage = sprIdle;
	buttonClicked = false;

	position.x = 0;
	position.y = 0;

	objectType = GUIT;
	messageBus::sharedMessageBus()->registerListener(leftMouseClickMessage, this);
	messageBus::sharedMessageBus()->sendMessage(entityCreatedEvent(GAME, objectType, this));
}

spellButton::~spellButton()
{
	messageBus::sharedMessageBus()->unRegisterListener(leftMouseClickMessage, this);
}

void spellButton::update()
{
	if (mouseClick())
	{
		messageBus::sharedMessageBus()->sendMessage(castSpellEvent(sName));
		std::cout << "sent castSpell" << std::endl;
	}
}
