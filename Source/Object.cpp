#include "Object.h"

Object::Object(double flameVelocity = 0.0, unsigned int maxBurnedDamage = 0, unsigned int width = 0, unsigned int height = 0, sf::Texture const * texture = NULL) :
	m_width(width),
	m_height(height),
	
	m_flameVelocity(flameVelocity),
	m_maxBurnedDamage(maxBurnedDamage),
	m_currentFlameIntensity(0),
	m_currentBurnedDamage(0),
	m_texture(texture),
	m_clock()
	
{	
	m_time = sf::seconds(0.0f);
	m_clock.restart();	
}

Object::~Object()
{
}

void Object::update(sf::Clock const & clk)
{
	m_time = m_clock.getElapsedTime();
}

void Object::draw(sf::RenderWindow * window) const
{
	sf::Sprite sprite;
        sprite.setTexture(*m_texture);
	window->draw(sprite);
}

void Object::ignite()
{
	
}

void Object::stopFire()
{
	m_currentFlameIntensity = 0;
}

int Object::getWidth() const
{
	return m_width; 
}

int Object::getHeight() const
{
	return m_height;
}




