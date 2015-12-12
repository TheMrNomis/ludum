#include "Object.h"

Object::Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height, sf::Texture const * texture) :
	m_flameVelocity(flameVelocity),
	m_maxBurnedDamage(maxBurnedDamage),
	m_currentFlameIntensity(0),
	m_currentBurnedDamage(0),
	m_width(width),
	m_height(height),
	m_texture(texture)
{
}

Object::~Object(){

}

void Object::draw() const
{
	this->draw();
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
