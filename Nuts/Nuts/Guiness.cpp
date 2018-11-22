#include"Guiness.h"

#include"input.h"
using namespace yam2d;
Guiness::Guiness(int gameObjectType, Texture* texture, TmxMap* map)
	: SpriteGameObject(gameObjectType, texture), 	collisionMap(map)
{
}

bool Guiness::doesCollide()
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


Guiness::~Guiness(void)
{
}

void Guiness::update( float deltaTime )
{
}