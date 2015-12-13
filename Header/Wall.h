#pragma once

#include "Object.h"
#include "INCollisionable.h"
#include "Ray.h"

class Wall : public Object, public INCollisionable
{
	public:
		Wall(sf::Texture * wallTexture);
		virtual ~Wall();

		virtual void collision(Ray * ray);
};

