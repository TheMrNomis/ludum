#pragma once
#include "INDrawable.h"
#include "Building.h"
#include "Floor.h"

class World : public INDrawable
{
	private:
		TextureLoader m_textures;
		Building m_building;
		Character m_character;

	public:
		World();
		virtual ~World();

		Character const * getCharacter() const;

		virtual void draw(sf::RenderWindow *window) const;
};

