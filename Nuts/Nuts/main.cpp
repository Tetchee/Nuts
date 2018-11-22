// Include OpenGL ES Engine utils
#include <es_util.h>
#include <Map.h>
#include<SpriteBatch.h>
#include<SpriteSheet.h>
#include<AnimatedSpriteGameObject.h>
#include<SpriteGameObject.h>
#include <Camera.h>
#include <Tile.h>
#include <Layer.h>
#include <Texture.h>
#include <TextGameObject.h>
#include <Input.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <irrKlang.h>
#include "player.h"
#include"Guiness.h"
#include "Drunkbar.h"
#include "Drunkblock.h"
#include "Defscreen.h"
#include "Enemy.h"
#include "Drunkbar2.h"
#include "Mustekalascreen.h"

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

int Drunknessp2 = 5;
int Drunkness = 5;
float count = 0.0f;
float count2 = 0;
using namespace yam2d;
int gameState=0;

namespace
{
	player* pelaaja = 0;
	Guiness* guiness = 0;
	Drunkbar* drunkbar = 0;
	Defscreen* defscreen = 0;
	Enemy* enemy = 0;
	Drunkbar2* drunkbar2 = 0;
	Mustekalascreen* mustekalascreen = 0;

	// Pointer to TmxMap-object
	TmxMap* map = 0;

	Ref<Texture> texture = 0;
	Ref<SpriteSheet> spriteSheet = 0;

	irrklang::ISoundEngine* engine;
}

// Initialize the game
bool init ()
{

	// Create new TmxMap object
	map = new TmxMap();

	vec2 tileSize(32,32);



	if( !map->loadMapFile("Mappisaatanat.tmx") )
		return false;

	// Move gameobject to middle of map.
	vec2 cameraPos = vec2(map->getWidth()/2.0f - 0.5f, map->getHeight()/2.0f - 0.5f);
	map->getCamera()->setPosition( cameraPos );

	
	// Add player to map layer named "GameObjects".
	{
		// Load texture.
		Texture* playerTexture = new Texture("marketsquid.png");
		playerTexture->setTransparentColor(255, 0, 255);
		spriteSheet = SpriteSheet::generateSpriteSheet(playerTexture, 32, 32, 0, 0);

		pelaaja = new player(0, spriteSheet, map);
		pelaaja->setSize(31, 31);
		pelaaja->setName("squiddy");

		int numClipsPerAnimation = 4;

		float animationFrameRate = 10.0f;
		for( int i=0; i<4; ++i )
		{
			std::vector<int> indices;
			indices.resize(numClipsPerAnimation);
			for( size_t j=0; j<indices.size(); ++j )
			{
				indices[j] = numClipsPerAnimation*i + j;
			}

			// Add looping animation.
			pelaaja->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
		}
		pelaaja->setActiveAnimation(0);


		pelaaja->setPosition(10,10);
		// Add it to GameObjects-layer.
		map->getLayer("PERSE")->addGameObject(pelaaja);
	}

	{
		Texture* enemyTexture = new Texture("vuohipukki.png");
		enemyTexture->setTransparentColor(255, 0, 255);
		spriteSheet = SpriteSheet::generateSpriteSheet(enemyTexture, 32, 32, 0, 0);

		enemy = new Enemy(0, spriteSheet, map);
		enemy->setSize(31, 31);
		enemy->setName("goat");

		int numClipsPerAnimation = 4;

		float animationFrameRate = 5.0f;
		for( int i=0; i<4; ++i )
		{
			std::vector<int> indices;
			indices.resize(numClipsPerAnimation);
			for( size_t j=0; j<indices.size(); ++j )
			{
				indices[j] = numClipsPerAnimation*i + j;
			}

			// Add looping animation.
			enemy->addAnimation(i, SpriteAnimation::SpriteAnimationClip(indices,animationFrameRate, 1.0f, true));
		}
		enemy->setActiveAnimation(0);

		enemy->setPosition(6,6);
		// Add it to GameObjects-layer.
		map->getLayer("PERSE")->addGameObject(enemy);
	
	}

	{

		Texture* GuinessTexture = new Texture("Guiness.png");
		GuinessTexture->setTransparentColor(255, 0, 255);

		guiness = new Guiness(0, GuinessTexture, map);
		guiness -> setSize(31, 31);
		guiness ->setName("olunen");

		guiness->setPosition(20, 20);
		map->getLayer("PERSE")->addGameObject(guiness);

		Texture* DrunkbarTexture = new Texture("EsSheet.png");
		DrunkbarTexture->setTransparentColor(255, 0, 255);
		spriteSheet = SpriteSheet::generateSpriteSheet(DrunkbarTexture, 147, 40, 0, 0);
		drunkbar = new Drunkbar(0, spriteSheet, map);
		drunkbar ->setSize(147, 40);
		drunkbar -> setName("baarilol");
		drunkbar -> setPosition(2, 2);
		map->getLayer("PERSE")->addGameObject(drunkbar);

		Texture* Drunkbar2Texture = new Texture("EsSheet.png");
		Drunkbar2Texture->setTransparentColor(255, 0, 255);
		spriteSheet = SpriteSheet::generateSpriteSheet(Drunkbar2Texture, 147, 40, 0, 0);
		drunkbar2 = new Drunkbar2(0, spriteSheet, map);
		drunkbar2 ->setSize(147, 40);
		drunkbar2 -> setName("baarilol2");
		drunkbar2 -> setPosition(17, 2);
		map->getLayer("PERSE")->addGameObject(drunkbar2);

		Texture* DefscreenTexture = new Texture("Vuohiscreen.png");
		DefscreenTexture->setTransparentColor(255, 0, 255);
		defscreen = new Defscreen(0, DefscreenTexture, map);
		defscreen ->setPosition(12, 12);
		defscreen -> setSize(1280, 720);
		defscreen ->setName("fobbakaksoispistedee");
		
		Texture* MustekalascreenTexture = new Texture("Mustekalascreen.png");
		MustekalascreenTexture->setTransparentColor(255, 0, 255);
		mustekalascreen = new Mustekalascreen (0, MustekalascreenTexture, map);
		mustekalascreen ->setPosition(12, 12);
		mustekalascreen -> setSize(1280, 720);
		mustekalascreen ->setName("fobbakaksoispistedeeM");
	}




	 


	return true; 
}


// Deinitialize the game
void deinit ( ESContext *esContext )
{
		// Delete map.

	delete map;
	//delete player;
	//delete enemy;
	//delete guiness;
	//delete drunkbar;
	//delete defscreen;
	//delete mustekalascreen;
	//delete drunkbar2;
	texture = 0;
	spriteSheet = 0;
}


// Draw game
void draw ( ESContext *esContext )
{
// Set OpenGL clear color (dark gray)
	glClearColor( 0.1f, 0.1f, 0.1f, 0.0f );

	// Clear the color buffer
	glClear ( GL_COLOR_BUFFER_BIT );

	// Set screen size to camera.
	map->getCamera()->setScreenSize(esContext->width,esContext->height); 

	// Render map and all of its layers containing GameObjects to screen.
	map->render();
}


// update game
void update( ESContext*, float deltaTime )
{
	switch (gameState)
	{
		case 0:
			{
		// Update map. this will update all GameObjects inside a map layers.
		map->update(deltaTime);
		count += deltaTime;
		count2 += deltaTime;

		if (count > 2)
		{
			Drunkness--;
			std::cout<< "lol testi" << std::endl;
			count = 0.0f;
		}

		if (count2 > 2)
		{
			Drunknessp2--;
			std::cout<< "lol testi" << std::endl;
			count2 = 0.0f;
		}

		

		if (pelaaja->collidesTo(guiness))
		{
			std::cout<<"asd"<<std::endl;
			/*map->deleteGameObject(guiness);*/
			do
			{
				guiness->setPosition(rand() % 24, rand() % 24);
			}
			while (guiness->doesCollide());
			Drunkness++;
			count = 0.0f;
		}
		
		if (enemy->collidesTo(guiness))
		{
			std::cout<<"asdi"<<std::endl;
			/*map->deleteGameObject(guiness);*/
			do
			{
				guiness->setPosition(rand() % 24, rand() % 24);
			}
			while (guiness->doesCollide());
			Drunknessp2++;
			count2 = 0.0f;
		}


			switch (Drunkness)
			{
				case 0:
					gameState = 1;
					break;
				case 6:
					Drunkness =5;
					break;
				default:
					drunkbar->setIdInSpriteSheet(Drunkness-1);
					break;
			}

			switch (Drunknessp2)
			{
				case 0:
					gameState = 2;
					break;
				case 6:
					Drunknessp2 = 5;
					break;
				default:
					drunkbar2->setIdInSpriteSheet(Drunknessp2-1);
					break;
			}
			}
			break;
		case 1:
			map->getLayer("Def")->addGameObject(defscreen);
			break;
		case 2:
			map->getLayer("Def")->addGameObject(mustekalascreen);
			break;
	}

}

// Main function 
int main ( int argc, char *argv[] )
{
	// start the sound engine with default parameters
    engine = irrklang::createIrrKlangDevice();

   engine->play2D("ragtiem.mp3", true);

   srand(time(NULL));

	ESContext esContext;
	esInitContext ( &esContext );
	esCreateWindow( &esContext, "Nuts t3h game", 1280, 720, ES_WINDOW_DEFAULT );

	if ( !init ( ) )
		return 0;

	esRegisterDrawFunc( &esContext, draw );
	esRegisterUpdateFunc( &esContext, update );
	esRegisterDeinitFunc( &esContext, deinit);

	esMainLoop ( &esContext );
	return 0;
}
