#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "INDrawable.h"
#include "INCollisionable.h"

#include "TextureLoader.h"
#include "Character.h"
#include "Ray.h"

class Door : public INDrawable, public INCollisionable
{
private:
	unsigned int m_x;
	unsigned int m_y;

	std::pair<unsigned int, unsigned> m_adjacentRooms;

	const sf::Texture * m_texture;

public:
	Door(unsigned int x, unsigned int y, std::pair<unsigned int, unsigned int> adjacentRooms, sf::Texture const * texture);
	virtual ~Door();

	/**
	* @brief draw the door
	*
	* @param window:
	*
	*/
	virtual void draw(sf::RenderWindow *window) const;

	virtual void collision(Ray * ray);

	void collisionCharacter(Ray * ray, Character * character);
};
