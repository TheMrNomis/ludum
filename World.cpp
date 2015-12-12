#include "World.h"


World::World()
{
	m_building = new Building(new Floor());
}


World::~World()
{
}

void World::draw(sf::RenderWindow *window) 
{

	m_building->draw(window);
}