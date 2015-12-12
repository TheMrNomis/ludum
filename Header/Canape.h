#pragma once

#include "Object.h"

class Canape : public Object
{
	public:
	/**
         * @brief constuctor for Canape
         *
         * @param texture: contains the texture of canape
         */
	Canape(sf::Texture const * texture);
	
/**
         * @brief destructor for Canape
         *
         */
	virtual ~Canape();

};
