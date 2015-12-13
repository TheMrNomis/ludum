#pragma once

#include "INDrawable.h"
#include "INCollisionable.h"

#include "Ray.h"

class Room;

class FireDetector : public INDrawable, public INCollisionable
{
    public:
	 /**
	 * @brief constuctor for FireDetector
         *
         * @param radius: the range of the FIreDetector 
         * @param parentRoom: the room where the FIreDectector is inside
         */
        FireDetector(double radius, Room * parentRoom);

	/**
	*@brief	draw the FIreDetector
	*
	*/
        virtual void draw(sf::RenderWindow * window) const;
        
	/**
	*@brief send a ray to find a collision with a floor or objects
	*
	*@param ray: the ray who will intersect somethings or not
	*/
	virtual void collision(Ray * ray);

    private:
        Room * m_parentRoom;
        double const m_radius;
        bool m_isActivated;
};
