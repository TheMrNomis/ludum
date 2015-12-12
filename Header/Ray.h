#pragma once

#include <SFML/System/Vector2.hpp>

#include "Vector2fOperations.h"
#include "INCollisionable.h"

class Ray
{
    public:
        Ray(sf::Vector2f const& origin, sf::Vector2f const& direction);

        void intersect(INCollisionable & object);

        bool validIntersectionFound() const;
        sf::Vector2f intersection() const;

        sf::Vector2f getOrigin() const;
        sf::Vector2f getDirection() const;
        
        void setIntersection(float t);

        bool intersectCircle(sf::Vector2f circleCenter, float radius, bool saveIntersection = true);
        bool intersectSquare(sf::Vector2f pointMin, sf::Vector2f pointMax, bool saveIntersection = true);

    private:
        sf::Vector2f m_origin;
        sf::Vector2f m_direction;

        bool m_intersectionFound;
        float m_minT;
};
