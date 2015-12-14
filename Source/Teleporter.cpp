#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(sf::Texture * texture,unsigned int targetFloor) : 
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

void Teleporter::draw(sf::RenderWindow * window) const
{
    sf::Sprite sprite;
    sprite.setTexture(*m_texture);
	if (m_targetFloor == 0){
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
		sprite.setPosition(450, 100);
	}
	else{
		sprite.setTextureRect(sf::IntRect(0, 0, 32, 64));
		sprite.setPosition(500, 100);
	}
    window->draw(sprite);
}

