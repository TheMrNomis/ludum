#include "World.h"


World::World():
	m_textures(TextureLoader("Ressources/sprites/")),
	m_building(Building(&m_textures, 1, 1)),
	m_character(new Character())
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

void World::update()
{
	m_building.update();
	m_character->update();

	if (!m_building.checkCollision(m_building.getCurrentFloor(), *(m_character->getSprite())))

	//Deplacement
	while(m_character->isMoving())
	{
	sf::Vector2f position = m_character->getPosition() 
							+ m_character->getDirection()*m_character->getVelocity();
	//	Ray intersectionRay(m_character->getPosition(), m_character->getDirection()*m_character->getVelocity());
		
		//std::cout << m_building.getWalls()->size() << std::endl;

		//Recherche de collisions
	//	for(auto i = 0; i < m_building.getWalls()->size(); i++)
		//{}

		m_character->setPosition(position);


		//
		//m_character->move(m_character->getDirection()*m_character->getVelocity);
	}
}
