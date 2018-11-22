#include "Drunkbar.h"
#include "Input.h"

using namespace yam2d;

Drunkbar::Drunkbar(int gameObjectType, SpriteSheet* spriteSheet, TmxMap* map)
	: SpriteSheetGameObject(gameObjectType, spriteSheet, 4)
{
}

Drunkbar::~Drunkbar(void)
{
}

void Drunkbar::update( float deltaTime )
{
}