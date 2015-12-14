#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "INDrawable.h"
#include "INCollisionable.h"

#include "TextureLoader.h"
#include "Ray.h"

class Door : public INDrawable, public INCollisionable
{
	private:
		unsigned int m_x;
		unsigned int m_y;

		const sf::Texture * m_texture;

	public:
		Door(unsigned int x, unsigned int y, sf::Texture * texture);
		virtual ~Door();

		/**
		* @brief draw the door
		*
		* @param window:
		*
		*/
		virtual void draw(sf::RenderWindow *window) const;
        
        virtual void collision(Ray * ray);
};
