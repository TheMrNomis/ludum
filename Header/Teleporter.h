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
	unsigned int m_x;
	unsigned int m_y;

public:

	Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture * texture, unsigned int targetFloor );
		virtual ~Teleporter();

		unsigned int getX() const ;
		unsigned int getY() const;
		virtual void update(sf::Clock const & clk) ;
		void draw(sf::RenderWindow * window) const;
};


