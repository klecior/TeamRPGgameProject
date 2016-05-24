
enum messages
{
	noEvent,changeStateMessage, getCurrentStateMessage,getMousePosMessage, leftMouseClickMessage, changeHealthMessage, changeStaminaMessage,
	playerControlsMessage, entityCreatedMessage, entityDeletedMessage,hitPlayerMessage, castSpellMessage, getPlayerStatsMessage,moveWorldMessage,
	objectsCollidedMessage, quitGameMessage, addStatusEffectMessage, removeStatusEffectMessage, removeAllStatusEffectMessage, statusEffectEndedMessage
};

enum spellNames
{
	fireBallSpell, healSpell,teleportSpell
};

enum statusEffectMessages
{
	onFireEffect, speedBoostEffect, armourBoostEffect, healingEffect, testStatus
};