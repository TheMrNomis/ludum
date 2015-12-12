#pragma once
#include "INDrawable.h"
#include "Building.h"
#include "Floor.h"

class World : public INDrawable
{
private:
	Building m_building;
	TextureLoader m_textures;

public:
	World();
	virtual ~World();


	virtual void draw(sf::RenderWindow *window) const;

};

