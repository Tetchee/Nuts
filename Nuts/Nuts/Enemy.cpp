#include"Enemy.h"
#include "Input.h"

using namespace yam2d;

Enemy::Enemy(int gameObjectType, SpriteSheet* spriteSheet, TmxMap* map)
	: AnimatedSpriteGameObject(gameObjectType,spriteSheet),
	collisionMap(map)
{
}

bool Enemy::doesCollide()
{
	std::vector< Ref<GameObject>> collision = collisionMap->getLayer("Collision")->getGameObjects();
	for (int i = 0; i < collision.size(); i++)
    {
         if (collidesTo(collision[i]))
         {
              return true;
          }
    }
	return false;
}

Enemy::~Enemy(void)
{
}

void Enemy::update( float deltaTime )
{
	AnimatedSpriteGameObject::update(deltaTime);
	vec2 playerPos = getPosition();
	movementDelay -= deltaTime;

	if (movementDelay > 0)
	{
		return;
	}	

	if (getKeyState(KEY_W) == 1)
	{
		playerPos.y -= 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_S) == 1)
	{
		playerPos.y += 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_A) == 1)
	{
		playerPos.x -= 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_D) == 1)
	{
		playerPos.x += 1;
		movementDelay = 0.09;
	}

	std::vector< Ref<GameObject>> collision = collisionMap->getLayer("Collision")->getGameObjects();

	vec2 lastEnemyPos = getPosition();
	setPosition(playerPos.x, playerPos.y);
		
    for (int i = 0; i < collision.size(); i++)
    {
         if (collidesTo(collision[i]))
         {
              setPosition(lastEnemyPos);
              return;
          }
    }

}