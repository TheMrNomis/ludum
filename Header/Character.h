#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "Ray.h"
#include "INDrawable.h"
#include "INUpdatable.h"
#include "TextureLoader.h"



class Character : public INDrawable, public INUpdatable
{
	enum StateAnimation{
		Left,
		Midle,
		Right
	};


	private: 
		//sf::Sprite * m_spriteCharater;
		//sf::Sprite * m_arrow;
		//const TextureLoader * m_textures;
        const sf::Texture * m_texture;

        sf::Vector2f m_position;
		unsigned int m_currentAnimation;

        sf::Time m_lastAnimationUpdate;

		const float m_velocity;
		bool m_jumping;
		bool m_statusCollision;


		double m_angleJump;
		Ray	m_intersectionRay;
		
		double m_distanceToCollision = 0;


	public:
		/**
		* @brief constuctor for Character
		*
		*/
		Character(TextureLoader * textures);

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
		double  getAngle() const ;


		void setDistanceToCollision(double distance);

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
		sf::Vector2f nextFramePosition();
	
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

		sf::Sprite  *getArrowSprite() const;



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
		Ray * jump();

		/**
		* @brief Check if the caracter is moving
		*
		*/
		bool isJumping();

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
		virtual void update(sf::Clock const & clk);


};

