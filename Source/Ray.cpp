#include "Ray.h"

Ray::Ray(sf::Vector2f const& origin, sf::Vector2f const& direction):
    m_origin(origin),
    m_direction(direction),
    m_intersectionFound(false),
    m_minT(0)
{
}

void Ray::intersect(INCollisionable & object)
{
    object.collision(this);
}

bool Ray::validIntersectionFound() const
{
    return m_intersectionFound;
}

sf::Vector2f Ray::intersection() const
{
    return m_origin + m_direction*m_minT;
}
