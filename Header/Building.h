#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iterator>   
#include "INDrawable.h"
#include "INUpdatable.h"
#include <iostream>
#include "Character.h"
#include "Floor.h"
#include "Wall.h"

class Building : public INDrawable,public INUpdatable
{
	private:
		
		unsigned int m_largeur;
		unsigned int m_longueur;
		const unsigned int m_maxBurnedDamage;
		const unsigned int m_currentBurnedDamage;

		const TextureLoader * m_textureLoader;

		std::vector<Floor *> m_floors;
		std::vector<Wall *> m_walls;
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


		void initWalls(std::vector<std::vector<unsigned char> > map);
		std::vector<Wall *> * getWalls();


		std::vector<Floor * > getFloors();

		unsigned int getCurrentFloor();

		bool checkCollision(unsigned int idFloor, sf::Sprite & sprite);


		virtual void update();

		/**
		*@brief show the building
		*
		*@param window: window whitch containt the building
		*/	
		virtual void draw(sf::RenderWindow *window) const ;

		/**
		*@brief charge the level from files
		*
		*@param window: window whitch containt the building
		*/
		void loadToTileSet(std::string const & path);
};

