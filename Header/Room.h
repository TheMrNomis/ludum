#pragma once

#include <vector>

#include "INDrawable.h"
#include "Object.h"
#include "FireDetector.h"
#include "INUpdatable.h"

class Room : public INUpdatable, public INCollisionable
{
    private:
		const unsigned int m_roomId;
        std::vector<Object *> m_objects;
        std::vector<FireDetector *> m_fireDetectors;

    public:
        Room(unsigned char roomId);
        virtual ~Room();

        /**
         * @brief add an object to the room
         *
         * @param obj: the object to add (dynamically-created pointer)
         * @note this takes ownership of the object, and will delete it when needed
         */
        virtual void addObject(Object * obj);

		virtual std::vector<Object *> getObject();
		
		virtual std::vector<FireDetector *> getfireDetector();
		
		/**
         * @brief adds a fire detector to the room
         *
         * @param fd: the fireDetector to add (dynamically-created pointer)
         * @note this takes ownership of the FireDetector, and will delete it when needed
         */
        virtual void addFireDetector(FireDetector * fd);

        /**
         * @brief Exteguish all the fire in the room
         *		the damage is stoped
         *
         */
        void extinguishFire();

		/**
		* @brief Collisions test on all objects
		*		
		*
		*/
        virtual void collision(Ray * ray);

		/**
         * @brief draw the Room
         *
         * @param window:
         *
         */
        virtual void draw(sf::RenderWindow * window, std::vector<std::vector<unsigned char> > const * floorMap) const;


        /**
         * @brief update the room
         *
         *
         */
        virtual void update(sf::Clock const& clk);
};
