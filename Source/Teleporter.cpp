#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture const* texture, unsigned char  direction) :
    m_x(positionX),
    m_y(positionY),

	m_direction(direction),
	m_inCollision(false),

	m_texture(texture),
	
	m_directionIn(sf::Vector2f()),
	m_positionIn(sf::Vector2f())
{

}

Teleporter::~Teleporter()
{}

void Teleporter::update(sf::Clock const & clk)
{
 
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

	int texture = (m_direction == 'd') ? 0 : 1;

	sprite.setTextureRect(sf::IntRect(texture * 32, 0, 32, 64));
	sprite.setPosition(m_x,m_y);
    window->draw(sprite);
}

bool Teleporter::getStatusColision()
{
	return m_inCollision;
}

void Teleporter::collision(Ray * ray)
{
    bool collision = ray->intersectSquare(sf::Vector2f(m_x , m_y ),
		sf::Vector2f((m_x+32) , (m_y+32) ),true);
	
	if (collision == true && ray->distanceToIntersection() < 32)
		m_inCollision = true;

	else
		m_inCollision = false;
}

 unsigned char Teleporter::getDirection()
{
	return m_direction;
}