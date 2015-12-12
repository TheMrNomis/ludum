#pragma once
#include<SFML/Graphics.hpp>
#include "INDrawable.h"

class Character : public INDrawable
{
private: 
	sf::Sprite * m_spriteCharater;
	sf::Texture * m_textureCharacter;


public:
	Character();
	virtual ~Character();


	//Return the direction which facing the character
	sf::Vector2i getDirection();

	//Set the new direction of the character
	void setDirection(sf::Vector2i & direction);

	virtual void draw();


};

