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
	if(character->isMoving())
	{
		if(!m_building.checkCollisions(intersectionRay))
		{
			std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
			m_character->setPosition(character->nextFramePosition());
			m_character->setStatusCollision(false);
		}

		else
		{
			std::cout << "distance to intersection: " << intersectionRay.distanceToIntersection() << std::endl;

			if(intersectionRay.distanceToIntersection() > character->getVelocity())
			{
				std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
				m_character->setPosition(character->nextFramePosition());
			}

			else
			{
				std::cout << "/!\\ Collision /!\\" << std::endl;
				m_character->setMoving(false);
				m_character->setStatusCollision(true);
			}
		}
	}
}

void World::update(sf::Clock const & clk)
{
	m_building.update(clk);
	m_character->update( clk);
	moveCharacter(m_character);
	

}
