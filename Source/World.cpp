#include "World.h"

World::World(TextureLoader * textures):
	m_textures(textures),
	m_building(new Building(m_textures, 1, 1)),
	m_character(new Character('A',m_textures)),
	m_musicGame(new sf::Music())
{
	m_building->loadToTileSet("Levels/0.lvl");

	if (m_musicGame->openFromFile("Ressources/Music/Game.wav"))
	{
		m_musicGame->setLoop(true);
	}
}

World::~World()
{
	delete m_building;
	delete m_character;
	delete m_musicGame;
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
	if (m_building->getCurrentFloor()->isItHit())
		m_character->die();
}
