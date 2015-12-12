#include "Building.h"


Building::Building(Floor * floor, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage ):
m_floors(floor), m_maxBurnedDamage(maxBurnedDamage), m__currentBurnedDamage(currentBurnedDamage)
{
}


Building::~Building()
{
}
void Building::draw(sf::RenderWindow *window)
{
	m_floors->draw(window);

}