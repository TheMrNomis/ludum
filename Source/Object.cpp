#include "Object.h"

Object::Object(double flameVelocity=0.0, unsigned int maxBurnedDamage=0, unsigned int width=0, unsigned int height=0, sf::Texture const * texture =NULL) :
	m_width(width),
	m_height(height),
	
	m_flameVelocity(flameVelocity),
	m_maxBurnedDamage(maxBurnedDamage),
	m_currentFlameIntensity(0),
	m_currentBurnedDamage(0),

	m_texture(texture),
	m_sprite(new sf::Sprite())
{
	m_sprite->setTexture(*m_texture);
}

Object::~Object(){
	delete m_sprite;
}

void Object::draw(sf::RenderWindow * window) const
{
	window->draw(*m_sprite);
}

void Object::ignite()
{
}

void Object::stopFire()
{
}

int Object::getWidth()
{
	return m_width; 
}

int Object::getHeight()
{
	return m_height;
}
