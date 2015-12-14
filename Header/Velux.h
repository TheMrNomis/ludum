#pragma once
#include <SFML/Audio.hpp>

#include "INDrawable.h"
#include "INUpdatable.h"
#include "Ray.h"

#include "Floor.h"


class Velux : public INDrawable, public INUpdatable
{
	private:
		sf::Texture m_textures;

	public:
		Velux();

		virtual void draw(sf::RenderWindow *window) const;
		virtual void update(sf::Clock const & clk);
};

