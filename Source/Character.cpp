#include "Character.h"


Character::Character(): m_spriteCharater(new sf::Sprite()),m_textureCharacter(new sf::Texture())
{
	m_textureCharacter->loadFromFile("Build/Ressources/sprites/spooky/sprite.png");
	m_spriteCharater->setTexture(*m_textureCharacter);
	m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_spriteCharater->setPosition(sf::Vector2f(1, 1.));

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
	if (m_currentAnimation == StateAnimation::Left){
		m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));
		//m_currentAnimation = StateAnimation::Midle;
	}


	window->draw(*m_spriteCharater);
}