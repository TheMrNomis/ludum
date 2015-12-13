#include "Object.h"

#include <iostream>
static Object * Object::Bed(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.6,15, 2,3, 0,0, x,y, texture);
}

static Object * Object::Sofa(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.5,25, 2,1, 0,3, x,y, texture);
}

static Object * Object::Toilet(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.0,10, 1,1, 2,0, x,y, texture);
}

static Object * Object::Table(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(1.0,20, 1,1, 2,1, x,y, texture);
}

static Object * Object::Oven(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.5,50, 1,1, 2,2, x,y, texture);
}

static Object * Object::Fridge(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.5,50, 1,1, 2,3, x,y, texture);
}

static Object * Object::KitchenTable(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.5,50, 1,1, 3,0, x,y, texture);
}

static Object * Object::Tub(unsigned int x, unsigned int y, sf::Texture const* texture)
{
    return new Object(0.0,10, 1,2, 3,1, x,y, texture);
}


Object::Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height, unsigned int offsetX, unsigned int offsetY, unsigned int x, unsigned int y, sf::Texture const * texture) :
    m_width(width),
    m_height(height),

    m_x(x),
    m_y(y),

    m_offsetX(offsetX),
    m_offsetY(offsetY),

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

void Object::update()
{
    m_time = m_clock.getElapsedTime();
}

void Object::draw(sf::RenderWindow * window) const
{
    sf::Sprite sprite;
    sprite.setTexture(*m_texture);
    sprite.setTextureRect(sf::IntRect(32*m_offsetX, 32*m_offsetY, 32*m_width, 32*m_height));
    sprite.setPosition(m_x * 32, m_y * 32);
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
