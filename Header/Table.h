#pragma once

#include "Object.h"

class Table : public Object
{
	public:
	
	/**
         * @brief constuctor for Bed
         *
         * @param texture: contains the texture of the bed
         */

	Table(sf::Texture const * texture);

	/**
         * @brief destructor for Bed
         *
         */	
	virtual ~Table();

};
