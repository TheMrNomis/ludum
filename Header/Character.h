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

		const float m_velocity;
		bool m_moving;
		bool m_statusCollision;

		StateAnimation m_currentAnimation;

		int m_angleShot;


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
		* @brief set the angle before jummping
		*
		*/
		int  getAngle() const ;

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
		* @brief Get the current position of the character
		*
		*/
		sf::Vector2f getPosition();

		/**
		* @brief Get the new position of the character
		*	if he moves
		*
		*/
		sf::Vector2f newPositon();
	
		/**
		* @brief get if the character is in collision actually
		*	
		*
		*/
		bool getStatusCollision();
		
		/**
		* @brief set if the character is in collision or not
		*	
		*
		*/
		void setStatusCollision(bool isInCollision);


		/**
		* @brief Get the srpite of the character
		*
		*/
		sf::Sprite  * getSprite() const;
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
		* @brief set if the caracter is moving or not
		*
		*/
		void setMoving(bool isMoving);

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

