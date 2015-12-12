#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "INDrawable.h"

class Character : public INDrawable
{
	private: 
		sf::Sprite * m_spriteCharater;
		sf::Texture * m_textureCharacter;

		int m_angleShot = 90;
		float m_velocity = 50;

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
		* @brief set the angle before jummping
		*
		*/
		void setAngle(int alpha);

		/**
		* @brief Return the direction which facing the character
		*
		*/
		sf::Vector2f getDirection();

		/**
		* @brief Return the direction which facing the character
		*
		*/
		void jump();

		/**
		* @brief draw the character
		*
		* @param window: 
		*
		*/
		virtual void draw(sf::RenderWindow *window) const;


};

