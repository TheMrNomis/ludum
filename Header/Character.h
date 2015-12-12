#pragma once
#include<SFML/Graphics.hpp>
#include "INDrawable.h"

class Character : public INDrawable
{
private: 
	sf::Sprite * m_spriteCharater;
	sf::Texture * m_textureCharacter;


public:
	/**
         * @brief constuctor for Character
         *
         */
	Character();

	/**
	* @brief destructor for Character
	*/
	virtual ~Character();

	/**
	* @brief vReturn the direction which facing the character
	*
	*/
	sf::Vector2i getDirection();

	/**
	* @brief Set the new direction of the character
	*
	* @param direction: give the direction of the character want to go
	*/
	void setDirection(sf::Vector2i & direction);

	/**
	* @brief draw the character
	*
	* @param window: 
	*
	*/
	virtual void draw(sf::RenderWindow *window) const;


};

