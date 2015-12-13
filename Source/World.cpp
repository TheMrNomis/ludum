#include "World.h"


World::World():
	m_textures(TextureLoader("Ressources/sprites/")),
	m_building(new Building(&m_textures, 1, 1)),
	m_character(new Character(&m_textures))
{
	m_building->loadToTileSet("Levels/0.lvl");
}

World::~World()
{
	delete m_building;
	delete m_character;
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


void World::moveCharacter(Character * character)
{
	Ray intersectionRay(character->getPosition(),character->getDirection());

	//Deplacement
	if(character->isMoving())
	{
		m_building->checkCollisions(intersectionRay);
		//{
		//	std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
		//	m_character->setPosition(character->nextFramePosition());
		//	m_character->setStatusCollision(false);
		//}

		std::cout << "distance to intersection: " << intersectionRay.distanceToIntersection() << std::endl;

		if(intersectionRay.distanceToIntersection() <= 1)
		{
			std::cout << "/!\\ Collision /!\\" << std::endl;
			m_character->setMoving(false);
			m_character->setStatusCollision(true);
		}

		else
		{
			std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
			m_character->setPosition(character->nextFramePosition());
		}
	}
}

void World::update(sf::Clock const & clk)
{
	m_building->update(clk);
	m_character->update(clk);
	moveCharacter(m_character);
}
