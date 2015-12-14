#pragma once
#include <SFML/Audio.hpp>
#include "INDrawable.h"
#include "INUpdatable.h"
#include "Ray.h"

#include "Floor.h"


class Velux : public INDrawable, public INUpdatable
{
	private:
		unsigned int m_x;
		unsigned int m_y;

		sf::Texture m_textures;

	public:
		Velux(unsigned int x, unsigned y, sf::Texture textures);

		bool collisionCharacter(Character * character);
		void waterShoot();

		virtual void draw(sf::RenderWindow *window) const;
		virtual void update(sf::Clock const & clk);
};

