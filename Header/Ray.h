#pragma once
#include <SFML/System/Vector2.hpp>

class Ray
{
    public:
        Ray(sf::Vector2f const& origin, sf::Vector2f const& direction);

    private:
        sf::Vector2f m_origin;
        sf::Vector2f m_direction;
};
