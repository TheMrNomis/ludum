#pragma once

#include "INCollisionable.h"

#include "Object.h"
#include "Ray.h"


class Wall : public INCollisionable
{
	private:
		sf::Vector2f m_position;

	public:
		Wall(sf::Vector2f position);
		virtual ~Wall();

		virtual void collision(Ray * ray);
};

