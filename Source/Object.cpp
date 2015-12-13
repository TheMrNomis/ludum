#include "Object.h"

Object::Object(double flameVelocity = 0.0, unsigned int maxBurnedDamage = 0, unsigned int width = 0, unsigned int height = 0, sf::Texture const * texture = NULL):
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
	window->draw(*getSprite());
}

void Object::ignite()
{
	//1- gerer le changement d'image de pas en feu à objet en feu

	//2- gerer combien de degat prend l'objet seon le temps passser entre deux appel de fonction update   
}

void Object::stopFire()
{
}

int Object::getWidth() const
{
	return m_width; 
}

int Object::getHeight() const
{
	return m_height;
}

sf::Sprite * Object::getSprite() const{
	return m_sprite;
}


void Object::update()
{
	/*
	if (m_flameVelocity > 0)
		m_currentBurnedDamage *= m_currentFlameIntensity;
	*/
}