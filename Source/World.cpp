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


void World::managerDeplacement(Character * character)
{
	sf::Sprite * tmp = new sf::Sprite(*character->getSprite());
	sf::Vector2f nextFramePosition = m_character->nextFramePosition();
	tmp->setPosition(nextFramePosition);

	//Deplacement
	if(character->isMoving() && !m_building.checkCollisionWall(m_building.getCurrentFloor(), *(tmp)))
	{
		//std::cout << "/!\\ Pas de Collisions /!\\" << std::endl;
		m_character->setStatusCollision(false);
		m_character->setPosition(nextFramePosition);
	}

	else
	{
		//std::cout << "/!\\ Collision /!\\" << std::endl;
		m_character->setStatusCollision(true);
		m_character->setMoving(false);
	}
		
	delete tmp;
}

void World::update(sf::Clock const & clk)
{
	m_building.update(clk);
	m_character->update(clk);
	managerDeplacement(m_character);
	
}
