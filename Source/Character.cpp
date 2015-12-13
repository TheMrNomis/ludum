#define _USE_MATH_DEFINES

#include "Character.h"


Character::Character(TextureLoader * textures):
    m_spriteCharater(new sf::Sprite()),
    m_textures(textures),
    m_velocity(20),
    m_moving(false),
    m_statusCollision(false),
    m_currentAnimation(StateAnimation::Right),
    m_angleShot(0)
{
	m_spriteCharater->setTexture(*m_textures->getCharacterTexture());
    m_spriteCharater->setPosition(sf::Vector2f(200,200));
}

Character::~Character()
{
    delete m_spriteCharater;
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
}

void Character::jump()
{	
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

sf::Vector2f Character::nextFramePosition()
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
	if (rand()%10 == 0)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(64,0, 32, 32));
	}
	else{

		if (m_currentAnimation == StateAnimation::Left)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(0, 32, 32, 32));
			m_currentAnimation = StateAnimation::Midle;
		}

		else if (m_currentAnimation == StateAnimation::Midle)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(32, 32, 32, 32));
			m_currentAnimation = StateAnimation::Right;
		}

		else if (m_currentAnimation == StateAnimation::Right)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(64, 32, 32, 32));
			m_currentAnimation = StateAnimation::Midle;
		}
	}


}
