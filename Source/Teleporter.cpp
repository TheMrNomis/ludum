#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture const* texture, unsigned char direction) :
    m_texture(texture),
    m_x(positionX),
    m_y(positionY),
	m_inCollision(false),
	m_directionIn(sf::Vector2f()),
	m_positionIn(sf::Vector2f())
{
	m_direction = (direction == 'd') ? 0 : 1;
}

Teleporter::~Teleporter()
{}

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

bool Teleporter::getStatusColision()
{
	return m_inCollision;
}
void Teleporter::collision(Ray * ray)
{
    bool collision = ray->intersectSquare(sf::Vector2f(m_x * 32, m_y * 32), sf::Vector2f((m_x+1/*width*/) * 32, (m_y+1/*height*/) * 32));
	
	if (collision){
		m_inCollision = true;
		std::cout << "collision with : " << m_direction ;
	}
	else
		m_inCollision = false;
}

unsigned int Teleporter::getDirection()
{
	return m_direction;
}