#pragma once

#include <SFML/System/Vector2.hpp>

#include "INCollisionable.h"

class Ray
{
    public:
        Ray(sf::Vector2f const& origin, sf::Vector2f const& direction);

        void intersect(INCollisionable & object);

        bool validIntersectionFound() const;
        sf::Vector2f intersection() const;

    private:
        sf::Vector2f m_origin;
        sf::Vector2f m_direction;

        bool m_intersectionFound;
        float m_minT;
};
