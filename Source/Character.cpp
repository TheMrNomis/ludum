#define _USE_MATH_DEFINES

#include "Character.h"


Character::Character() :
m_spriteCharater(new sf::Sprite()),
m_textureCharacter(new sf::Texture()),
m_statusCollision(false)
{
	m_textureCharacter->loadFromFile("Ressources/sprites/spooky/sprite.png");
	m_spriteCharater->setTexture(*m_textureCharacter);
	m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));

	m_spriteCharater->setPosition(sf::Vector2f(200,200));
}

Character::~Character()
{
	delete m_spriteCharater;
	delete m_textureCharacter;
}

void Character::setAngle(int alpha)
{
	m_angleShot += alpha;
}
int Character::getAngle() const
{
	return m_angleShot;
}

float Character::getVelocity()
{
	return m_velocity;
}

sf::Vector2f Character::getDirection()
{
	return sf::Vector2f(cos(m_angleShot * M_PI_2/360), sin(m_angleShot * M_PI_2/360));
}

sf::Vector2f Character::getPosition()
{
	return m_spriteCharater->getPosition();
}

void Character::setPosition(sf::Vector2f position)
{
	m_spriteCharater->setPosition(position);
	m_moving = false;
}

void Character::jump()
{	
	//???? à quoi sa sert Mr Alexis :p 
	//m_position = m_spriteCharater->getPosition();
	m_moving = true;
}


bool Character::getStatusCollision(){
	return m_statusCollision;
}

void Character::setStatusCollision(bool isInCollision){
	m_statusCollision = isInCollision;
}



bool Character::isMoving()
{
	return m_moving;
}

void Character::setMoving(bool isMoving){
	m_moving = isMoving;
}


sf::Sprite * Character::getSprite() const
{
	return m_spriteCharater;
}

sf::Vector2f Character::newPositon()
{
return getPosition() + getDirection()*getVelocity();
}


void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);
}



void Character::update()
{


	//Animations
	if(m_currentAnimation == StateAnimation::Left)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));
		m_currentAnimation = StateAnimation::Midle;
	}

	else if(m_currentAnimation == StateAnimation::Midle)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(32, 0, 32, 32));
		m_currentAnimation = StateAnimation::Right;
	}
	
	else if(m_currentAnimation == StateAnimation::Right)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(32, 64, 32, 32));
		m_currentAnimation = StateAnimation::Left;
	}
	else
	{
		m_spriteCharater->setTextureRect(sf::IntRect(0, 0, 32, 32));
		m_currentAnimation = StateAnimation::Right;
	}



}
