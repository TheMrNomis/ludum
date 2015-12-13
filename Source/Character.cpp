#define _USE_MATH_DEFINES
#define TEXTURE_DIMENSION 32
#include "Character.h"


Character::Character(TextureLoader * textures) :
    m_texture(textures->getCharacterTexture()),

    m_position(200, 200),
    m_currentAnimation(0),

    m_velocity(20),
    m_jumping(false),
    m_statusCollision(false),

    m_angleJump(90),
    m_intersectionRay(sf::Vector2f(0, 0), sf::Vector2f(0, 0))
{
}

Character::~Character()
{
}

void Character::setAngle(int alpha)
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

	m_intersectionRay = Ray(getPosition(), getDirection());

	return &m_intersectionRay;
}

bool Character::getStatusCollision()
{
    return m_statusCollision;
}

void Character::setStatusCollision(bool isInCollision)
{
    m_statusCollision = isInCollision;
}

bool Character::isJumping()
{
    return m_jumping;
}

void Character::setMoving(bool isMoving){

    if (isMoving == false)
    {
    }
    m_jumping = isMoving;
}

sf::Vector2f Character::nextFramePosition()
{
    return getPosition() + getDirection()*getVelocity();
}

void Character::draw(sf::RenderWindow *window) const
{
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
}
