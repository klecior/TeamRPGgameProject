#include "gameObject.h"
#include "messageBus.h"
//events
#include "entityCreatedEvent.h"
#include "entityDeletedEvent.h"
#include "moveWorldEvent.h"

class sceneryObject : public gameObject
{
protected:

	bool isAnimated;
	int onFrame;

	textureImage*		objectImage;
	sequenceAnimation*	objectAnimation;



public:

	sceneryObject(int atState, bool solid, std::string imagePath, int x, int y);
	sceneryObject(int atState, bool solid, bool animated, int frames, std::string animationPath, int x, int y);
	~sceneryObject();

	void handleMessage(abstractEvent& msgEvent);

	void collidedWith(gameObject* object);

	void update();

};