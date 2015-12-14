#pragma once
#include <SFML/Audio.hpp>

#include "INDrawable.h"
#include "INUpdatable.h"
#include "Ray.h"

#include "Building.h"
#include "Floor.h"
#include "Character.h"
#include "Ray.h"
#include "Teleporter.h"

class World : public INDrawable, public INUpdatable
{
	private:
		TextureLoader m_textures;
		Building  * m_building;
		Character * m_character;
		//sf::Music * m_music;

	public:
		World();
		virtual ~World();

		Character * getCharacter() const;
		Building * getBuilding() const;

		virtual void draw(sf::RenderWindow *window) const;
		virtual void update(sf::Clock const & clk);
};

