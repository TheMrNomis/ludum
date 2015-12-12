#include "Building.h"




Building::Building(unsigned int maxBurnedDamage, unsigned int currentBurnedDamage ):
m_maxBurnedDamage(maxBurnedDamage), m_currentBurnedDamage(currentBurnedDamage), m_floors(std::vector<Floor *>()), m_currentFloor(0), m_idTileSet(std::vector<unsigned char>())
{
	
}


Building::~Building()
{
//	delete[] m_idTileSet;
}
void Building::draw(sf::RenderWindow *window) const
{
	m_floors[m_currentFloor]->draw(window);

	

}

//oublie pas la taillle de la ligne !!!!!!


void Building::loadToTileSet(std::string const &path)
{

	std::fstream myfile(path, std::ios_base::in);
	char currentChar = ' ';

	unsigned int currentId;
	int currentID =0;
	int currendFloor = 0;
	while (myfile >> currentChar)
	{
		if (currentChar == '\n')
			std::cout << "ok" << std::endl;
		if (currentChar == '='){
			m_floors.push_back(new Floor(m_idTileSet));
			currentID=0;
			std::cout << "endFloor" << std::endl;
		}
		else
		{
			m_idTileSet.push_back(currentChar);
		}
	}
	std::cout << "endBuild" << std::endl;
}