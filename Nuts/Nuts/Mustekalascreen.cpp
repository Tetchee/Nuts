#include "Mustekalascreen.h"
#include "Input.h"

using namespace yam2d;

Mustekalascreen::Mustekalascreen(int gameObjectType, Texture* texture, TmxMap* map)
	: SpriteGameObject(gameObjectType, texture)
{
}

Mustekalascreen::~Mustekalascreen(void)
{
}

void Mustekalascreen::update( float deltaTime )
{
}