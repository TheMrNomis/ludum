#include "Building.h"


Building::Building(unsigned int maxBurnedDamage, unsigned int currentBurnedDamage ):
m_maxBurnedDamage(maxBurnedDamage), m_currentBurnedDamage(currentBurnedDamage), m_floors(std::vector<Floor *>())
{
}


Building::~Building()
{
}
void Building::draw(sf::RenderWindow *window) const
{
	//m_floors->draw(window);

}


void Building::loadToTileSet()
{


}