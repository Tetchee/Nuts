#ifndef DRUNKBAR_H_
#define DRUNKBAR_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>
#include <SpriteSheetGameObject.h>

class Drunkbar : public yam2d::SpriteSheetGameObject
{
public:

	Drunkbar(int gameObjectType, yam2d::SpriteSheet* spriteSheet, yam2d::TmxMap* map);
	virtual ~Drunkbar(void);


	virtual void update( float deltaTime );
};

#endif