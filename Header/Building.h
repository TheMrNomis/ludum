#pragma once
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Floor.h"
#include <fstream>

class Building : public INDrawable
{
private:
	unsigned int m_maxBurnedDamage;
	unsigned int m_currentBurnedDamage;
	std::vector<Floor*> m_floors;
	unsigned int m_currentFloor;
	Character * m_character;


public:
	Building(unsigned int maxBurnedDamage=0, unsigned int currentBurnedDamage = 0);
	virtual ~Building();
	
	virtual void draw(sf::RenderWindow *window) const ;


	void loadToTileSet(char * path);



};

