#include "Object.h"
#include <iostream>

Object * Object::fromID(unsigned char objectID, unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    switch(objectID)
    {
        case 'a':
            return Bed(x,y,objectTexture, fireTexture);
            break;
        case 'b':
            return Sofa(x,y,objectTexture, fireTexture);
            break;
        case 'c':
            return Toilet(x,y,objectTexture, fireTexture);
            break;
        case 'd':
            return Table(x,y,objectTexture, fireTexture);
            break;
        case 'e':
            return Oven(x,y,objectTexture, fireTexture);
            break;
        case 'f':
            return Fridge(x,y,objectTexture, fireTexture);
            break;
        case 'g':
            return KitchenTable(x,y,objectTexture, fireTexture);
            break;
        case 'h':
            return Tub(x,y,objectTexture, fireTexture);
            break;
        default:
            return new Object(0,0,0,0,0,0,x,y,objectTexture, fireTexture);
            break;
    }

}

Object * Object::Bed(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.6,15, 2,3, 0,0, x,y, objectTexture, fireTexture);
}

Object * Object::Sofa(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.5,25, 2,1, 0,3, x,y, objectTexture, fireTexture);
}

Object * Object::Toilet(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.0,10, 1,1, 2,0, x,y, objectTexture, fireTexture);
}

Object * Object::Table(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(1.0,20, 1,1, 2,1, x,y, objectTexture, fireTexture);
}

Object * Object::Oven(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.5,50, 1,1, 2,2, x,y, objectTexture, fireTexture);
}

Object * Object::Fridge(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.5,50, 1,1, 2,3, x,y, objectTexture, fireTexture);
}

Object * Object::KitchenTable(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.5,50, 1,1, 3,0, x,y, objectTexture, fireTexture);
}

Object * Object::Tub(unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture)
{
    return new Object(0.0,10, 1,2, 3,1, x,y, objectTexture, fireTexture);
}


Object::Object(double flameVelocity, unsigned int maxBurnedDamage, unsigned int width, unsigned int height, unsigned int offsetX, unsigned int offsetY, unsigned int x, unsigned int y, sf::Texture * objectTexture, sf::Texture * fireTexture) :
    m_width(width),
    m_height(height),

    m_x(x),
    m_y(y),

    m_offsetX(offsetX),
    m_offsetY(offsetY),

	m_burn(false),
    m_flameVelocity(flameVelocity),
    m_maxBurnedDamage(maxBurnedDamage),
    m_currentFlameIntensity(0),
    m_currentBurnedDamage(0),
    m_objectTexture(objectTexture),
    m_fireTexture(fireTexture),
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
	if (m_burn)
	{

		m_currentBurnedDamage += m_currentFlameIntensity;
		if (m_currentBurnedDamage > m_maxBurnedDamage)
		{
			m_burn = false;
		}
	}
}

void Object::draw(sf::RenderWindow * window) const
{
    sf::Sprite sprite;
    sprite.setTexture(*m_objectTexture);
    sprite.setTextureRect(sf::IntRect(32*m_offsetX, 32*m_offsetY, 32*m_width, 32*m_height));
    sprite.setPosition(m_x * 32, m_y * 32);
    window->draw(sprite);
}

void Object::ignite(double fire)
{
	if (!m_burn)
	{
		m_burn = true;
		m_currentFlameIntensity = fire;
	}
}

void Object::stopFire()
{
    m_currentFlameIntensity = 0;
}


double Object::getMaxBurnedDamage() const
{
	return m_maxBurnedDamage;
}

int Object::getWidth() const
{
    return m_width; 
}

int Object::getHeight() const
{
    return m_height;
}

int Object::getX() const
{
	return m_x;
}

int Object::getY() const
{
	return m_y;
}

double Object::lifeLost() const
{
	return m_currentFlameIntensity;
}

void Object::collision(Ray * ray)
{
    ray->intersectSquare(sf::Vector2f(m_x*32, m_y*32), sf::Vector2f((m_x+m_width)*32, (m_y+m_height)*32), true, this);
}
