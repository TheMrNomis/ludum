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

	std::pair<unsigned char, unsigned char> m_adjacentRooms;

	const sf::Texture * m_texture;

public:
	Door(unsigned int x, unsigned int y, std::pair<unsigned char, unsigned char> adjacentRooms, sf::Texture const * texture);
	virtual ~Door();

	std::pair<unsigned char, unsigned char> const * getAdjacentRooms();

	virtual void collision(Ray * ray);
	virtual void draw(sf::RenderWindow *window) const;
};
