#include "Teleporter.h"
#include <iostream>


Teleporter::Teleporter(sf::Texture * texture,unsigned int targetFloor) : 
					   m_texture(texture),m_targetFloor(targetFloor)
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
    sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
    sprite.setPosition(32, 32);
    window->draw(sprite);
}

