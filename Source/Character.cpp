#include "Character.h"


Character::Character(): m_spriteCharater(new sf::Sprite()),m_textureCharacter(new sf::Texture())
{
	m_textureCharacter->loadFromFile("Build/Ressources/sprites/spooky/sprite.png");
	m_spriteCharater->setTexture(*m_textureCharacter);
	m_spriteCharater->setPosition(sf::Vector2f(1., 1.));
}

Character::~Character()
{
}

void Character::setAngle(int alpha)
{
	m_angleShot += alpha;
}

sf::Vector2f Character::getDirection()
{
	return sf::Vector2f(cos(m_angleShot), sin(m_angleShot));
}

void Character::jump()
{
	return;
}

void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);
}