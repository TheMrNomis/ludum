#include "Lit.h"

#include <iostream>

Lit::Lit(unsigned int x, unsigned int y, sf::Texture const * texture)
	: Object(0.6, 15, 2, 3, 0, 0, x, y, texture)
{
}
	
Lit::~Lit()
{
}
