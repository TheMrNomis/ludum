#include "World.h"


World::World()
{
	m_building = new Building();
}


World::~World()
{
}

void World::draw(sf::RenderWindow *window) const
{

	m_building->draw(window);
}
