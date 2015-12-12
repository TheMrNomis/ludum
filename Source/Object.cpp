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
}

void Object::light()
{
}

void Object::stopFire()
{
}
