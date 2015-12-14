#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture const* texture, unsigned int targetFloor, unsigned char direction) :
    m_texture(texture),
    m_x(positionX),
    m_y(positionY),
    m_targetFloor(targetFloor)
{
	m_direction = (direction == 'd') ? 0 : 1;
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
    sprite.setTexture(*m_texture);

	sprite.setTextureRect(sf::IntRect(m_direction * 32, 0, 32, 64));
	sprite.setPosition(m_x,m_y);

    window->draw(sprite);
}

void Teleporter::collision(Ray * ray)
{
    ray->intersectSquare(sf::Vector2f(m_x * 32, m_y * 32), sf::Vector2f((m_x+1/*width*/) * 32, (m_y+1/*height*/) * 32));
}
