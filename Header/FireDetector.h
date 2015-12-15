#pragma once
#include <SFML/Audio.hpp>

#include <iostream>

#include "INUpdatable.h"
#include "INDrawable.h"
#include "INCollisionable.h"

#include "Ray.h"

class Room;

class FireDetector : public INUpdatable, public INDrawable, public INCollisionable
{
    private:
        Room * m_parentRoom;
		
        sf::Texture const* m_texture;

        unsigned int m_x;
        unsigned int m_y;
        double const m_radius;

		bool m_isActivated;
		bool m_timerActivatedOK;
		sf::Time m_activationTime;
		
		sf::Music * m_musicFireDetector;

    public:
        /**
         * @brief constuctor for FireDetector
         *
         * @param radius: the range of the FIreDetector 
         * @param parentRoom: the room where the FIreDectector is inside
         */
        FireDetector(unsigned int x, unsigned int y, double radius, sf::Texture const* texture);

        virtual ~FireDetector();

        /**
         *@brief	draw the FIreDetector
         *
         */
        virtual void draw(sf::RenderWindow * window) const;

		virtual unsigned int getX() const;

		virtual unsigned int getY() const;

		virtual void activate();

		virtual bool isActivate() const;

        /**
         *@brief send a ray to find a collision with a floor or objects
         *
         *@param ray: the ray who will intersect somethings or not
         */
         virtual void collision(Ray * ray);

         virtual void update(sf::Clock const& clk);
};
