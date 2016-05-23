
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
	onFire, speedBoost, armourBoost, healing, testStatus
};