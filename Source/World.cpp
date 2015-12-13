#include "World.h"


World::World():
	m_textures(TextureLoader("Ressources/sprites/")),
	m_building(Building(&m_textures, 1, 1)),
	m_character(new Character(&m_textures))
{
	m_building.loadToTileSet("Levels/0.lvl");
}

World::~World()
{
	delete m_character;
}

Character * World::getCharacter() const
{
	return m_character;
}

void World::draw(sf::RenderWindow *window) const
{
	m_building.draw(window);
	m_character->draw(window);
}


void World::moveCharacter(Character * character)
{
	Ray intersectionRay(character->getPosition(),character->getDirection());

	//Deplacement
	if(character->isMoving() && !m_building.checkCollisions(intersectionRay))
	{
		//std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
		m_character->setStatusCollision(false);
		m_character->setPosition(character->nextFramePosition());
	}

	else
	{
		//std::cout << "/!\\ Collision /!\\" << std::endl;
		m_character->setStatusCollision(true);
		m_character->setMoving(false);
	}
}

void World::update()
{
	m_building.update();
	m_character->update();
	moveCharacter(m_character);
}
