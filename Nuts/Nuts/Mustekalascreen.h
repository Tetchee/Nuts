#ifndef MUSTEKALASCREEN_H_
#define MUSTEKALACREEN_H_ 

#include <Tile.h>
#include <Layer.h>
#include <Map.h>
#include <SpriteGameObject.h>
#include <SpriteSheetGameObject.h>


class Mustekalascreen : public yam2d::SpriteGameObject
{
public:

	Mustekalascreen(int gameObjectType, yam2d::Texture* Texture, yam2d::TmxMap* map);
	virtual ~Mustekalascreen(void);


	virtual void update( float deltaTime );
};



#endif