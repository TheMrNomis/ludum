#pragma once

#include "Object.h"

class Toilet : public Object
{
	public:
	
	/**
         * @brief constuctor for Bed
         *
         * @param texture: contains the texture of the bed
         */

	Toilet(sf::Texture const * texture);

	/**
         * @brief destructor for Bed
         *
         */	
	virtual ~Toilet();

};
