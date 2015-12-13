#include "Ray.h"

Ray::Ray(sf::Vector2f const& origin, sf::Vector2f const& direction):
    m_origin(origin),
    m_direction(direction),
    m_intersectionFound(false),
    m_minT(0)
{}

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

sf::Vector2f Ray::getOrigin() const
{
    return m_origin;
}

sf::Vector2f Ray::getDirection() const
{
    return m_direction;
}

void Ray::setIntersection(float t)
{
    if(!m_intersectionFound)
        m_minT = t;
    else
        m_minT = min(m_minT, t);

    m_intersectionFound = true;
}

bool Ray::intersectCircle(sf::Vector2f circleCenter, float radius, bool saveIntersection)
{
    float t = -scalar((m_origin - circleCenter), m_direction) / normSquare(m_direction);
    sf::Vector2f point = m_origin + t * m_direction;
    float dist = norm(point - circleCenter);

    bool intersection = dist <= radius;

    if(intersection && saveIntersection)
        setIntersection(t);
    
	return intersection;
}

bool Ray::intersectSquare(sf::Vector2f pointMin, sf::Vector2f pointMax, bool saveIntersection)
{
    float t1 = (pointMin.x - m_origin.x)/m_direction.x;
    float t2 = (pointMax.x - m_origin.x)/m_direction.x;

    float minX = min(t1, t2);
    float maxX = max(t1, t2);

    t1 = (pointMin.y - m_origin.y)/m_direction.y;
    t2 = (pointMax.y - m_origin.y)/m_direction.y;

    float minY = min(t1, t2);
    float maxY = max(t1, t2);

    float I = max(minX, minY);
    float M = min(maxX, maxY);

    bool intersection = I <= M;

    if(intersection && saveIntersection)
        setIntersection(I);

    return intersection;
}
