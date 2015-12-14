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
        virtual void update(sf::Clock const& clk);

        /**
         * @brief Exteguish all the fire in the room
         *		the damage is stoped
         *
         */
        void extinguishFire();


    private:
        std::vector<Object *> m_objects;
        std::vector<FireDetector *> m_fireDetectors;
};
