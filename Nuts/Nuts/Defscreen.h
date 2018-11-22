#ifndef DEFSCREEN_H_
#define DEFSCREEN_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>
#include <SpriteSheetGameObject.h>


class Defscreen : public yam2d::SpriteGameObject
{
public:

	Defscreen(int gameObjectType, yam2d::Texture* Texture, yam2d::TmxMap* map);
	virtual ~Defscreen(void);


	virtual void update( float deltaTime );
};



#endif