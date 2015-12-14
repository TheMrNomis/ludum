#include "World.h"

World::World(TextureLoader * textures):
m_textures(textures),
m_building(new Building(m_textures, 1, 1)),
m_character(new Character(m_textures)),
m_music(new sf::Music())
{
	m_building->loadToTileSet("Levels/0.lvl");

	m_music->openFromFile("Ressources/Music/Ambiante.wav");
	m_music->play();
}

World::~World()
{
	delete m_building;
	delete m_character;
	delete m_music;
}

Character * World::getCharacter() const
{
	return m_character;
}

Building * World::getBuilding() const
{
	return m_building;
}

void World::draw(sf::RenderWindow *window) const
{
	m_building->draw(window);
	m_character->draw(window);

}


void World::update(sf::Clock const & clk)
{
	m_building->update(clk);
	m_character->update(clk);
}
