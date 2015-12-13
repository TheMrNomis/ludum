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


void World::managerDeplacement(Character * character)
{

	//Deplacement
	if (character->isMoving())
	{
		sf::Sprite * tmp = new sf::Sprite(*character->getSprite());
		sf::Vector2f position = m_character->newPositon();
		tmp->setPosition(position);

		if (!m_building.checkCollisionWall(m_building.getCurrentFloor(), *(tmp))){
			m_character->setStatusCollision(false);
			m_character->setPosition(position);

		}
		else
		{
			m_character->setMoving(false);
			m_character->setStatusCollision(true);
		}
		
		delete tmp;
	}
}

void World::update()
{
	m_building.update();
	m_character->update();
	managerDeplacement(m_character);
	
}
