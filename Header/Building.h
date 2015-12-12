#pragma once
#include "INDrawable.h"
#include <SFML/Graphics.hpp>
#include "Header/Character.h"
#include "Header/Floor.h"

class Building : public INDrawable
{
private:
	unsigned int m_maxBurnedDamage;
	unsigned int m__currentBurnedDamage;
	//sf::Vector2<Floor*> m_floors;
	Floor* m_floors;

	Character * m_character;


public:
	Building();
	virtual ~Building();
	
	virtual void draw(sf::RenderWindow *window) ;





};

