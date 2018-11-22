#ifndef DRUNKBAR2_H_
#define DRUNKBAR2_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>
#include <SpriteSheetGameObject.h>

class Drunkbar2 : public yam2d::SpriteSheetGameObject
{
public:

	Drunkbar2(int gameObjectType, yam2d::SpriteSheet* spriteSheet, yam2d::TmxMap* map);
	virtual ~Drunkbar2(void);


	virtual void update( float deltaTime );
};

#endif