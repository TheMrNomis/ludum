#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(unsigned int positionX, unsigned int positionY, sf::Texture * texture, unsigned int targetFloor):
	m_texture(texture),

	m_x(positionX),
	m_y(positionY),
					   
	m_direction(42),
	m_targetFloor(targetFloor)
{

}

Teleporter::~Teleporter()
{
}

void Teleporter::update(sf::Clock const & clk)
{
 
}

void Teleporter::setDirection(unsigned int direction)
{
	m_direction = direction;
}

unsigned int Teleporter::getX() const
{
	return m_x;
}

unsigned int Teleporter::getY() const
{
	return m_y;
}

void Teleporter::draw(sf::RenderWindow * window) const
{
	sf::Sprite sprite;
   // sprite.setTexture(*m_texture);

	//sprite.setTextureRect(sf::IntRect(m_direction * 32, 0, 32, 64));
	//sprite.setPosition(m_x,m_y);

   // window->draw(sprite);
}

