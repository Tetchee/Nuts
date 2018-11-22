#ifndef GUINESS_H_
#define GUINESS_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>


class Guiness : public yam2d::SpriteGameObject
{
public:
		Guiness(int gameObjectType, yam2d::Texture* texture, yam2d::TmxMap* map);
	virtual ~Guiness(void);
	bool doesCollide();

	virtual void update( float deltaTime);
private:
	yam2d::TmxMap* collisionMap;
};

#endif