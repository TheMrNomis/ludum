#define _USE_MATH_DEFINES
#define TEXTURE_DIMENSION 32
#include "Character.h"


Character::Character(TextureLoader * textures) :
	m_spriteCharater(new sf::Sprite()),
	m_arrow(new sf::Sprite()),
	m_textures(textures),

	m_velocity(20),
	m_jumping(false),
	m_statusCollision(false),
	m_currentAnimation(StateAnimation::Right),
	
	m_angleJump(90),
	m_intersectionRay(sf::Vector2f(0, 0), sf::Vector2f(0, 0))
{
	m_spriteCharater->setTexture(*m_textures->getCharacterTexture());
	m_spriteCharater->setPosition(sf::Vector2f(200, 200));

	m_arrow->setTexture(*m_textures->getCharacterTexture());
	m_arrow->setTextureRect(sf::IntRect(0 * TEXTURE_DIMENSION, 0 * TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
	m_arrow->setPosition(getPosition() + sf::Vector2f(16, 16));
	m_arrow->setRotation(m_angleJump - 45);
}

Character::~Character()
{
	delete m_spriteCharater;
	delete m_arrow;
}

void Character::setAngle(int alpha)
{
	m_angleJump += alpha;

	if (m_angleJump > 360)
		m_angleJump = 0;

	else if (m_angleJump < 0)
		m_angleJump = 360;


}
double Character::getAngle() const
{
	return m_angleJump;
}




float Character::getVelocity()
{
	return m_velocity;
}

sf::Vector2f Character::getDirection()
{
	double cosT = cos(m_angleJump * M_PI / 180);
	double sinT = sin(m_angleJump * M_PI / 180);

	return sf::Vector2f(cosT, sinT);
}

sf::Vector2f Character::getPosition()
{
	return m_spriteCharater->getPosition();
}

void Character::setPosition(sf::Vector2f position)
{
	m_spriteCharater->setPosition(position);
}

Ray * Character::jump()
{
	m_arrow->setTextureRect(sf::IntRect(0 * TEXTURE_DIMENSION, 1 * TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
	m_jumping = true;

	m_intersectionRay = Ray(getPosition(), getDirection());

	return &m_intersectionRay;
}

bool Character::getStatusCollision(){
	return m_statusCollision;
}

void Character::setStatusCollision(bool isInCollision){
	m_statusCollision = isInCollision;
}

bool Character::isJumping()
{
	return m_jumping;
}

void Character::setMoving(bool isMoving){

	if (isMoving == false)
	{
		m_arrow->setPosition(getPosition() + sf::Vector2f(16, 16));
		m_arrow->setTextureRect(sf::IntRect(0 * TEXTURE_DIMENSION, 0 * TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
	}
	m_jumping = isMoving;
}


sf::Sprite * Character::getSprite() const
{
	return m_spriteCharater;
}

sf::Vector2f Character::nextFramePosition()
{
	return getPosition() + getDirection()*getVelocity();
}

sf::Sprite  * Character::getArrowSprite() const{
	return m_arrow;
}


void Character::draw(sf::RenderWindow *window) const
{
	window->draw(*m_spriteCharater);



	//triangle.move(sf::Vector2f(10,0));
	//m_arrow->rotate(m_angleJump);
	window->draw(*m_arrow);
}


void Character::update(sf::Clock const & clk)
{
	//Deplacement
	if(isJumping())
	{
		std::cout << "distance to intersection: " << m_intersectionRay.distanceToIntersection() << std::endl;

		if (m_intersectionRay.distanceToIntersection() <= 1)
		{
			std::cout << "/!\\ Collision /!\\" << std::endl;
			setMoving(false);
			setStatusCollision(true);
		}

		else
		{
			std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
			setPosition(nextFramePosition());
		}
	}

	//Animations
	if (/*rand()%10 */ 0 == -1)
	{
		m_spriteCharater->setTextureRect(sf::IntRect(TEXTURE_DIMENSION * 3, TEXTURE_DIMENSION * 0, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
	}

	else
	{
		if (m_currentAnimation == StateAnimation::Left)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
			m_currentAnimation = StateAnimation::Midle;
		}

		else if (m_currentAnimation == StateAnimation::Midle)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(TEXTURE_DIMENSION * 2, TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
			m_currentAnimation = StateAnimation::Right;
		}

		else if (m_currentAnimation == StateAnimation::Right)
		{
			m_spriteCharater->setTextureRect(sf::IntRect(TEXTURE_DIMENSION * 3, TEXTURE_DIMENSION, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
			m_currentAnimation = StateAnimation::Midle;
		}
	}
}