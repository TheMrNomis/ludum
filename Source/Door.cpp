#include "Door.h"

Door::Door(unsigned int x, unsigned int y, sf::Texture * texture) :
	m_x(x),
	m_y(y),
	m_texture(texture)
{}

Door::~Door()
{}



void Door::draw(sf::RenderWindow *window) const
{
	sf::Sprite sprite;
	sprite.setTexture(*m_texture);
	sprite.setTextureRect(sf::IntRect(3, 0, 32, 32));
	sprite.setPosition(m_x * 32, m_y * 32);
	window->draw(sprite);
}

void Door::collision(Ray * ray)
{
    ray->intersectSquare(sf::Vector2f(m_x*32, m_y*32), sf::Vector2f(m_x*32+31, m_y*32+31), false);
}
