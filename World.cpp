#include "World.h"


World::World()
{
}


World::~World()
{
}

void World::draw(sf::RenderWindow *window) 
{

	m_building->draw(window);
}