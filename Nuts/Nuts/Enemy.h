#ifndef ENEMY_H_
#define ENEMY_H_ 

// Include base class
#include <AnimatedSpriteGameObject.h>
#include <Tile.h>
#include <Layer.h>
#include <Map.h>


class Enemy : public yam2d::AnimatedSpriteGameObject
{
public:

	Enemy(int gameObjectType, yam2d::SpriteSheet* spriteSheet, yam2d::TmxMap* map);
	virtual ~Enemy(void);
	bool doesCollide();


	virtual void update( float deltaTime );
private:
	yam2d::TmxMap* collisionMap;
		float movementDelay;
};


#endif