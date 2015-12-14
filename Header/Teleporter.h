#pragma once

#include <SFML/Graphics.hpp>
#include "INUpdatable.h"
#include "INDrawable.h"

class Teleporter : public INUpdatable, public INDrawable
{
private:
	sf::Texture const*const m_texture;

	unsigned int m_x;
	unsigned int m_y;

	unsigned int m_direction;
	unsigned int m_targetFloor;

public:
	Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture const* texture,unsigned int targetFloor);
	virtual ~Teleporter();

    void setDirection(unsigned int direction);

	unsigned int getX() const;
	unsigned int getY() const;

	virtual void update(sf::Clock const & clk) ;
	virtual void draw(sf::RenderWindow * window) const;
};
