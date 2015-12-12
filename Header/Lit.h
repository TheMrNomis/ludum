#pragma once

#include "Object.h"

class Lit : public Object
{
	public:
	Lit(sf::Texture const * texture);
	
	virtual ~Lit();

};
