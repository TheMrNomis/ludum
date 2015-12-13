#pragma once
#include "INDrawable.h"
#include "INUpdatable.h"
#include "Ray.h"

#include "Building.h"
#include "Floor.h"
#include "Character.h"
#include "Ray.h"

class World : public INDrawable, public INUpdatable
{
	private:
		TextureLoader m_textures;
		Building m_building;
		Character * m_character;

	public:
		World();
		virtual ~World();

		Character * getCharacter() const;

		void moveCharacter(Character * caracter);

		virtual void draw(sf::RenderWindow *window) const;

        virtual void update(sf::Clock const & clk);
};

