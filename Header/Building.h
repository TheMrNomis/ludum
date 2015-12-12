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
		Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage = 0, unsigned int currentBurnedDamage = 0);
		virtual ~Building();
	
		void setLongueurBuilding(unsigned int longueur);
		void setLargeurBuilding(unsigned int largeur);

		virtual void draw(sf::RenderWindow *window) const ;
		void loadToTileSet(std::string const & path);
};

