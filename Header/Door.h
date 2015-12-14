#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ray.h"
#include "INDrawable.h"
#include "TextureLoader.h"

class Door : public INDrawable
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
};