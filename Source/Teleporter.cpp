#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(unsigned int positionX, unsigned int positionY,sf::Texture * texture, unsigned int targetFloor) :
					   m_x(positionX),
					   m_y(positionY),
					   m_texture(texture),m_targetFloor(targetFloor),
					   m_directionIn(sf::Vector2f())
{

}

Teleporter::~Teleporter()
{
}

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
	if (m_targetFloor == 0){
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
		sprite.setPosition(getX(),getY());
	}
	else{
		sprite.setTextureRect(sf::IntRect(32, 0, 32, 64));
		sprite.setPosition(getX(),getY());
	}
    window->draw(sprite);
}

