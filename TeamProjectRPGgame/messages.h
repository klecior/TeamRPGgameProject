
enum messages
{
	noEvent,changeStateMessage, getCurrentStateMessage,getMousePosMessage, leftMouseClickMessage, changeHealthMessage, changeStaminaMessage,
	playerControlsMessage, entityCreatedMessage, entityDeletedMessage,hitPlayerMessage, castSpellMessage, consumePotionMessage, getPlayerStatsMessage,moveWorldMessage,
	objectsCollidedMessage, quitGameMessage, playAudioMessage, addStatusEffectMessage, removeStatusEffectMessage, removeAllStatusEffectMessage, statusEffectEndedMessage
};

enum spellNames
{
	fireBallSpell, healSpell, teleportSpell
};

enum potionNames
{
	healingPotion, staminaPotion, manaPotion
};

enum statusEffectMessages
{
	onFireEffect, speedBoostEffect, armourBoostEffect, healingEffect, testStatus
};