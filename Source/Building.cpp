#include "Building.h"




Building::Building(unsigned int maxBurnedDamage, unsigned int currentBurnedDamage ):
m_maxBurnedDamage(maxBurnedDamage), m_currentBurnedDamage(currentBurnedDamage), m_floors(std::vector<Floor *>()), m_currentFloor(0)
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