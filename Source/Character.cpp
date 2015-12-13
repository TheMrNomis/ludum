#include "Character.h"


Character::Character(): 
	m_spriteCharater(new sf::Sprite()),
	m_textureCharacter(new sf::Texture())
{
	m_textureCharacter->loadFromFile("Ressources/sprites/spooky/sprite.png");
	m_spriteCharater->setTexture(*m_textureCharacter);
	m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_position = sf::Vector2f(1, 1.);
	m_spriteCharater->setPosition(sf::Vector2f(1, 1.));
}

Character::~Character()
{}

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
	//TO DO
	//while(!obstacles)
	{
		this->m_position = m_spriteCharater->getPosition() + this->getDirection()*m_velocity;
		m_spriteCharater->move(this->getDirection()*m_velocity);
	}
	return;
}

void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);
	}



void Character::update(){
	if (m_currentAnimation == StateAnimation::Left){
		m_spriteCharater->setTextureRect(sf::IntRect(32, 0, 32, 32));
		m_currentAnimation = StateAnimation::Midle;
	}
	else if (m_currentAnimation == StateAnimation::Midle){
		m_spriteCharater->setTextureRect(sf::IntRect(32, 32, 32, 32));
		m_currentAnimation = StateAnimation::Midle;
	}
	else if (m_currentAnimation == StateAnimation::Right){
		m_spriteCharater->setTextureRect(sf::IntRect(32, 64, 32, 32));
		m_currentAnimation = StateAnimation::Left;

	}
}
