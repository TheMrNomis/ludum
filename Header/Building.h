#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <iterator>   

#include "INDrawable.h"
#include "INUpdatable.h"

#include "FireDetector.h"
#include "Object.h"
#include "TextureLoader.h"
#include "Character.h"
#include "Floor.h"
#include "Room.h"
#include "Wall.h"

class Building : public INDrawable, public INUpdatable
{
	private:
		
		unsigned int m_largeur;
		unsigned int m_longueur;
		const unsigned int m_maxBurnedDamage;
		const unsigned int m_currentBurnedDamage;

		const TextureLoader * m_textureLoader;

		std::vector<Floor *> m_floors;
		const unsigned int m_currentFloor;

	public:
		 /**
        	 * @brief constuctor for building
        	 *
        	 * @param textureLoader: the link of the texture file
        	 * @param maxBurnedDamage: Number max of domage for building
		 * @param currentBurnedDamage: actual Number of domage il the building
        	 */
		Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage = 0, unsigned int currentBurnedDamage = 0);

		/**
         	* @brief destructor for Canape
         	*
         	*/
		virtual ~Building();

		std::vector<Floor * > * getFloors();

		unsigned int getCurrentFloor();

		/**
		*@brief check if the sprite is intersecting a wall in the floor number idFloor
		*
		*@param idFloor : the floor which we want to check if there are any collision
		*@param sprite : the sprite which collide or not any wall in the floor
		*/
		bool checkCollisions(Ray & rayIntersection);
		/**
		*@brief charge the level from files
		*
		*@param window: window whitch containt the building
		*/
		void loadToTileSet(std::string const & path);

		/**
		*@brief show the building
		*
		*@param window: window whitch containt the building
		*/	
		virtual void draw(sf::RenderWindow *window) const ;

        /**
         * @brief updates this
         */
		virtual void update(sf::Clock const & clk);
};

