#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "INDrawable.h"
#include "INUpdatable.h"
#include "Ray.h"



class Character : public INDrawable, public INUpdatable
{
	enum StateAnimation{
		EyeCloseLeft,
		EyeCloseMidle,
		EyeCloseRight,
		Left,
		Midle,
		Right
	};


	private: 
		sf::Sprite * m_spriteCharater;
		sf::Texture * m_textureCharacter;

		float m_velocity = 10;
		bool m_moving = false;

		sf::Vector2f m_position;

		StateAnimation m_currentAnimation;

	public:
		int m_angleShot = 90;


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
		* @brief Get the velocity of the character
		*
		*/
		float getVelocity();

		/**
		* @brief Return the direction which facing the character
		*
		*/
		sf::Vector2f getDirection();

		/**
		* @brief Get the position of the character
		*
		*/
		sf::Vector2f getPosition();

		/**
		* @brief Set the position of the character
		*
		* @param position:
		*
		*/
		void setPosition(sf::Vector2f position);

		/**
		* @brief Return the direction which facing the character
		*
		*/
		void jump();

		/**
		* @brief Check if the caracter is moving
		*
		*/
		bool isMoving();

		/**
		* @brief draw the character
		*
		* @param window: 
		*
		*/
		virtual void draw(sf::RenderWindow *window) const;

		/**
		* @brief update the character
		*
		*
		*/
		virtual void update();


};

