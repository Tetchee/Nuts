// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// http://code.google.com/p/yam2d/
//
// Copyright (c) 2013 Mikko Romppainen
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in the
// Software without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies
// or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#include "player.h" // Include Player class header

#include "Input.h"

using namespace yam2d;



player::player(int gameObjectType, SpriteSheet* spriteSheet, TmxMap* map)
	: AnimatedSpriteGameObject(gameObjectType,spriteSheet),
	movementDelay(0.5),
	collisionMap(map)
{
}


player::~player(void)
{
}

void player::update( float deltaTime )
{
	AnimatedSpriteGameObject::update(deltaTime);
	vec2 playerPos = getPosition();
	movementDelay -= deltaTime;

	std::vector< Ref<GameObject>> collision = collisionMap->getLayer("Collision")->getGameObjects();

	if (movementDelay > 0)
	{
		return;
	}	
	

	if (getKeyState(KEY_UP) == 1)
	{
		playerPos.y -= 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_DOWN) == 1)
	{
		playerPos.y += 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_LEFT) == 1)
	{
		playerPos.x -= 1;
		movementDelay = 0.09;
	}

	if (getKeyState(KEY_RIGHT) == 1)
	{
		playerPos.x += 1;
		movementDelay = 0.09;
	}

	vec2 lastPlayerPos = getPosition();
	setPosition(playerPos.x, playerPos.y);
		
    for (int i = 0; i < collision.size(); i++)
    {
         if (collidesTo(collision[i]))
         {
              setPosition(lastPlayerPos);
              return;
          }
    }
}

