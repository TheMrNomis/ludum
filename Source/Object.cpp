#include "Object.h"

Object::Object(double flameVelocity, unsigned int maxBurnedDamage):
    m_flameVelocity(flameVelocity),
    m_maxBurnedDamage(maxBurnedDamage),
    m_currentFlameIntensity(0),
    m_currentBurnedDamage(0)
{
}

void Object::draw() const
{
	//TODO
	//this->draw();
}

void Object::ignite()
{
}

void Object::stopFire()
{
}
