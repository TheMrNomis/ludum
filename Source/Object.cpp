#include "Object.h"

Object::Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height):
    m_flameVelocity(flameVelocity),
    m_maxBurnedDamage(maxBurnedDamage),
    m_currentFlameIntensity(0),
    m_currentBurnedDamage(0),
    m_width(width),
    m_height(height)
{
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

int getWidth()
{
	return m_width; 
}

int getHeight()
{
	return m_height;
}
