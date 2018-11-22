#include "Defscreen.h"
#include "Input.h"

using namespace yam2d;

Defscreen::Defscreen(int gameObjectType, Texture* texture, TmxMap* map)
	: SpriteGameObject(gameObjectType, texture)
{
}

Defscreen::~Defscreen(void)
{
}

void Defscreen::update( float deltaTime )
{
}