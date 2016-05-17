
enum messages
{
	noEvent,changeStateMessage, getCurrentStateMessage,getMousePosMessage, leftMouseClickMessage, changeHealthMessage, changeStaminaMessage,
	playerControlsMessage, entityCreatedMessage, entityDeletedMessage,hitPlayerMessage, castSpellMessage, getPlayerStatsMessage,moveWorldMessage,
	objectsCollidedMessage, quitGameMessage, addStatusEffectMessage, removeStatusEffectMessage, removeAllStatusEffectMessage
};

enum spellNames
{
	fireBallSpell, healSpell,teleportSpell
};

enum statusEffects
{
	onFire, speedBoost, armourBoost, healing, testStatus
};