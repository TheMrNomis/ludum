#include "Building.h"




Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage):
	m_floors(std::vector<Floor const *>()),
	m_currentFloor(0),

	m_textureLoader(textureLoader),

	m_maxBurnedDamage(maxBurnedDamage), 
	m_currentBurnedDamage(currentBurnedDamage) 
{
	
}

Building::~Building()
{
}

void Building::draw(sf::RenderWindow *window) const
{
	m_floors[m_currentFloor]->draw(window);

}

void Building::loadToTileSet(char * path)
{

	std:: ifstream myfile;
	myfile.open(path);



	m_floors.push_back(new Floor());
}