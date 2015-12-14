#define _USE_MATH_DEFINES
#define TEXTURE_DIMENSION 32
#include "Character.h"


Character::Character(TextureLoader * textures) :
    m_texture(textures->getCharacterTexture()),

    m_position(200, 200),
    m_currentAnimation(0),

    m_velocity(1.4),
    m_jumping(false),
    m_statusCollision(false),

    m_angleJump(90),
    m_collisionRay(sf::Vector2f(0, 0), sf::Vector2f(0, 0))
{
    m_lastAnimationUpdate = sf::milliseconds(0);
}

Character::~Character()
{
}

void Character::setAngle(double alpha)
{
    if(!m_jumping)
    {
        m_angleJump += alpha;

        if (m_angleJump > 360)
            m_angleJump = 0;

        else if (m_angleJump < 0)
            m_angleJump = 360;
    }

}

double Character::getAngle() const
{
    return m_angleJump;
}

void Character::setDistanceToCollision(double distance)
{
	m_distanceToCollision = distance;
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
    return m_position;
}

void Character::setPosition(sf::Vector2f position)
{
    m_position = position;
}

Ray * Character::jump()
{
    m_jumping = true;
	m_collisionRay = getCollisionRay();
	return &m_collisionRay;
}

Ray Character::getCollisionRay()
{
	return Ray(getPosition() + sf::Vector2f(16, 16), getDirection());
}

bool Character::getStatusCollision()
{
    return m_statusCollision;
}

void Character::setCurrentRoom(std::pair<unsigned int, unsigned> adjacentRooms)
{
	if (m_currentRoom == adjacentRooms.first)
		m_currentRoom = adjacentRooms.second;
	else
		m_currentRoom = adjacentRooms.first;
}

void Character::setStatusCollision(bool isInCollision)
{
    m_statusCollision = isInCollision;
}

bool Character::isJumping()
{
    return m_jumping;
}

sf::Vector2f Character::nextFramePosition()
{
    return getPosition() + getDirection()*getVelocity();
}

void Character::draw(sf::RenderWindow *window) const
{
    if(m_jumping)
    {
        sf::Sprite sprite;
        sprite.setTexture(*m_texture);
        sprite.setTextureRect(sf::IntRect(TEXTURE_DIMENSION*(m_currentAnimation%8), 4*TEXTURE_DIMENSION, TEXTURE_DIMENSION, 2*TEXTURE_DIMENSION));
        sprite.setOrigin(16,TEXTURE_DIMENSION+16);
        sprite.setRotation(m_angleJump-90);
        sprite.setPosition(m_position.x + 16, m_position.y + 16);
        window->draw(sprite);
    }
    else
    {
        sf::Sprite sprite;
        sprite.setTexture(*m_texture);
        sprite.setTextureRect(sf::IntRect(TEXTURE_DIMENSION*(m_currentAnimation%12), 2*TEXTURE_DIMENSION, TEXTURE_DIMENSION, 2*TEXTURE_DIMENSION));
        sprite.setOrigin(0,TEXTURE_DIMENSION);
        sprite.setPosition(m_position);
        window->draw(sprite);

        sf::Sprite spriteArrow;
        spriteArrow.setTexture(*m_texture);
        spriteArrow.setTextureRect(sf::IntRect(8*TEXTURE_DIMENSION, 0, TEXTURE_DIMENSION, TEXTURE_DIMENSION));
        spriteArrow.setOrigin(-9,15);
        spriteArrow.setPosition(m_position.x+(TEXTURE_DIMENSION/2), m_position.y+(TEXTURE_DIMENSION/2));
        spriteArrow.setRotation(m_angleJump);
        window->draw(spriteArrow);
        //TODO: eyes

        sf::Sprite eyeSprite;
        eyeSprite.setTexture(*m_texture);
        unsigned int direction_regard = (unsigned int)floor(((float)m_angleJump+135.0)*8.0/360)%8; //between 0 and 7
        eyeSprite.setTextureRect(sf::IntRect(TEXTURE_DIMENSION*direction_regard, 0, TEXTURE_DIMENSION, 2*TEXTURE_DIMENSION));
        eyeSprite.setOrigin(0, TEXTURE_DIMENSION);
        eyeSprite.setPosition(m_position);
        eyeSprite.move(0,-3);
        window->draw(eyeSprite);
    }
    /*
    sf::Sprite sprite;
    sprite.setTexture(*m_texture);
    sprite.setTextureRect(sf::IntRect(32*(m_currentAnimation+1), 0, 32, 32));
    sprite.setPosition(m_position);
    window->draw(sprite);
    

    if(!m_jumping)
    {
        sf::Sprite spriteArrow;
        spriteArrow.setTexture(*m_texture);
        spriteArrow.setTextureRect(sf::IntRect(0,0,32,32));
        spriteArrow.setPosition(m_position.x, m_position.y);
        spriteArrow.move(16,16);
        spriteArrow.setOrigin(-9,15);
        spriteArrow.setRotation(m_angleJump);
        window->draw(spriteArrow);
    }
    */
}

void Character::update(sf::Clock const & clk)
{
    sf::Time elapsedTime = clk.getElapsedTime();

    //Deplacement
    if(isJumping())
    {
		m_distanceToCollision -= m_velocity;

        if(m_distanceToCollision <= 10)
        {
            m_jumping = false;
            setStatusCollision(true);
			m_distanceToCollision = 0;
        }

        else setPosition(nextFramePosition());
    }

    if((elapsedTime - m_lastAnimationUpdate).asMilliseconds() >= 200)
    {
        m_currentAnimation = (m_currentAnimation+1)%96;

        m_lastAnimationUpdate = elapsedTime;
    }
}
