#include "Wall.h"


Wall::Wall(sf::Texture * wallTexture) : Object(1,1,32,32,wallTexture)
{}


Wall::~Wall()
{}

void Wall::collision(Ray * ray)
{
	
}
