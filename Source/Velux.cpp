#include "Velux.h"

Velux::Velux(unsigned int x, unsigned y, sf::Texture textures):
	m_x(x),
	m_y(y),

	m_textures(textures)
{

}

bool Velux::collisionCharacter(Character * character)
{
	//TO DO
	return false;
}

void Velux::waterShoot()
{
	//TO DO
}

void Velux::draw(sf::RenderWindow *window) const
{
	sf::Sprite sprite;
	sprite.setTexture(m_textures);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	sprite.setPosition(m_x * 32, m_y * 32);
	window->draw(sprite);
}

void Velux::update(sf::Clock const & clk)
{

}
