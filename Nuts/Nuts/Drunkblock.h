#ifndef DRUNKBLOCK_H_
#define DRUNKBLOCK_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>

class Drunkblock : public yam2d::SpriteGameObject
{
public:

	Drunkblock(int gameObjectType, yam2d::Texture* Texture, yam2d::TmxMap* map);
	virtual ~Drunkblock(void);


	virtual void update( float deltaTime );
};

#endif