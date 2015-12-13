#pragma once

#include <SFML/System/Vector2.hpp>

#include "Vector2fOperations.h"
#include "INCollisionable.h"

class Ray
{
    private:
        sf::Vector2f m_origin;
        sf::Vector2f m_direction;

        bool m_intersectionFound;
        float m_minT;

    public:
        /**
         * @brief constuctor for Ray
         *
         * @param origin: origin of the ray
         * @param direction: vector director of the ray
         */
        Ray(sf::Vector2f const& origin, sf::Vector2f const& direction);

        /**
         * @brief intersects this ray with an INcollisionable object
         *
         * @param object: the object to intersect this ray with
         */
        void intersect(INCollisionable & object);

        /**
         * @brief has a valid intersection be found?
         *
         * @return true if an intersection has been found, false otherwise
         */
        bool validIntersectionFound() const;

        /**
         * @brief gets the intersection
         *
         * @return the position of the intersection
         * @warning behavior undefined if validIntersectionFound() = false
         */
        sf::Vector2f intersection() const;

		float distanceToIntersection() const;
        /**
         * @return the origin of the ray
         */
        sf::Vector2f getOrigin() const;

        /**
         * @return the vector director of the ray
         */
        sf::Vector2f getDirection() const;
        
        /**
         * @brief adds a new intersection to the ray
         *
         * @param t: the value of the t param at the moment of the intersection [ (x,y) = origin() + t*direction() ]
         */
        void setIntersection(float t);

        /**
         * @brief computes the intersection between this ray and a circle
         *
         * @param circleCenter: the center of the intersected circle
         * @param radius: the radius of the intersected circle
         * @param saveIntersection: should the ray remember that the intersection happened ?
         *
         * @return true if the ray intersects the circle
         */
        bool intersectCircle(sf::Vector2f circleCenter, float radius, bool saveIntersection = true);

        /**
         * @brief computes the intersection between this ray and an axis-aligned rectangle
         *
         * @param pointMin: the first corner of the rectangle
         * @param pointMax: the corner opposite of pointMin
         * @param saveIntersection: should the ray remember that the intersection happened ?
         *
         * @return true if the ray intersects the rectangle
         */
        bool intersectSquare(sf::Vector2f pointMin, sf::Vector2f pointMax, bool saveIntersection = true);

};
