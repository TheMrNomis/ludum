#pragma once

#include <vector>

#include "INDrawable.h"
#include "Object.h"
#include "FireDetector.h"
#include "INUpdatable.h"

class Room : public INDrawable, public INUpdatable
{
    public:
        Room();


		/**
		* @brief draw the Room
		*
		* @param window:
		*
		*/
		virtual void draw(sf::RenderWindow * window) const;


		/**
		* @brief update the room
		*
		*
		*/
		virtual void update();

		/**
		* @brief Exteguish all the fire in the room
		*		the damage is stoped
		*
		*/
        void extinguishFire();


    private:
        std::vector<Object> m_objects;
        std::vector<FireDetector> m_fireDetectors;
};
