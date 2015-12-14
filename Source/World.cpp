#include "World.h"


World::World() :
m_textures(TextureLoader(PATH_RESSOURCE)),
m_building(new Building(&m_textures, 1, 1)),
m_character(new Character(&m_textures))
{
	m_building->loadToTileSet("Levels/0.lvl");
	
	// Open the mp3 from a file...
	std::cout << "Open MP3" << std::endl;
	player->OpenFromFile("Ressources/music/Ambiante.mp3");

	std::cout << "Start playing" << std::endl;
	player->Play();
}

World::~World()
{
	delete m_building;
	delete m_character;
	
	player->Close();
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
