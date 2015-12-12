#pragma once
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Floor.h"

class Building : public INDrawable
{
private:
	unsigned int m_maxBurnedDamage;
	unsigned int m_currentBurnedDamage;
	sf::Vector2<Floor*> m_floors;
	//Floor* m_floors;

	Character * m_character;


public:
	Building(unsigned int maxBurnedDamage=0, unsigned int currentBurnedDamage = 0);
	virtual ~Building();
	
	virtual void draw(sf::RenderWindow *window) const ;


	void loadToTileSet();


};

