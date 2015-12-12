#pragma once
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Floor.h"
#include <fstream>

class Building : public INDrawable
{
	private:
		
		unsigned int m_largeur;
		unsigned int m_longueur;

		std::vector<Floor *> m_floors;
		const unsigned int m_currentFloor;

		const TextureLoader * m_textureLoader;
		
		const unsigned int m_maxBurnedDamage;
		const unsigned int m_currentBurnedDamage;

		


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

		/**
		*@brief show the building
		*
		*@param window: window whitch containt the building
		*/	
		void setLongueurBuilding(unsigned int longueur);
		void setLargeurBuilding(unsigned int largeur);

		virtual void draw(sf::RenderWindow *window) const ;

		/**
		*@brief charge the level from files
		*
		*@param window: window whitch containt the building
		*/
		void loadToTileSet(std::string const & path);
};

