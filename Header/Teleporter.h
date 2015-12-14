#pragma once

#include <SFML/Graphics.hpp>
#include "INUpdatable.h"
#include "INDrawable.h"

class Teleporter : public INUpdatable
{
private:

	const unsigned int m_targetFloor;
	sf::Texture * m_texture;
	sf::Vector2f m_directionIn;

public:

		Teleporter(sf::Texture * texture, unsigned int targetFloor);
		virtual ~Teleporter();
		virtual void update(sf::Clock const & clk) ;
		void Teleporter::draw(sf::RenderWindow * window) const;
};


