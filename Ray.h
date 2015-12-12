#pragma once

#include <SFML/Vector2.hpp>

class Ray
{
    public:
        Ray(sf::Vector2d const& origin, sf::Vector2d const& direction);

    private:
        sf::Vector2d m_origin;
        sf::Vector2d m_direction;
};
