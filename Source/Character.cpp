#define _USE_MATH_DEFINES

#include "Character.h"


Character::Character(): 
	m_spriteCharater(new sf::Sprite()),
	m_textureCharacter(new sf::Texture())
{
	m_textureCharacter->loadFromFile("Ressources/sprites/spooky/sprite.png");
	m_spriteCharater->setTexture(*m_textureCharacter);
	m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_position = sf::Vector2f(320, 100.);
	m_spriteCharater->setPosition(m_position);
}

Character::~Character()
{}

void Character::setAngle(int alpha)
{
	m_angleShot += alpha;
}

sf::Vector2f Character::getDirection()
{
	return sf::Vector2f(cos(m_angleShot * M_PI_2/360), sin(m_angleShot * M_PI_2/360));
}

void Character::jump()
{	
	m_moving = true;
}

void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);
}



void Character::update()
{
	std::cout << "test" << std::endl;

	//Deplacement
	while(m_moving)
	{
		this->m_position = m_spriteCharater->getPosition() + this->getDirection()*m_velocity;
		m_spriteCharater->move(this->getDirection()*m_velocity);
	}


	//Animations
	if(m_currentAnimation == StateAnimation::Left)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(32, 0, 32, 32));
		m_currentAnimation = StateAnimation::Midle;
	}

	else if(m_currentAnimation == StateAnimation::Midle)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(32, 32, 32, 32));
		m_currentAnimation = StateAnimation::Midle;
	}
	
	else if(m_currentAnimation == StateAnimation::Right)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(32, 64, 32, 32));
		m_currentAnimation = StateAnimation::Left;
	}
}
