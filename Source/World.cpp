#include "World.h"


World::World() :
	m_textures(TextureLoader("Build/Ressources/sprites/")),
	m_building(Building(&m_textures, 1, 1))
{}

World::~World()
{}

void World::draw(sf::RenderWindow *window) const
{
	m_building.draw(window);
}
