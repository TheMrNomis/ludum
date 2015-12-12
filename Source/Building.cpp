#include "Building.h"




Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage):
	m_floors(std::vector<Floor *>()),
	m_currentFloor(0),

	m_textureLoader(textureLoader),
	//m_idTileSet(std::vector<unsigned char>()),

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

//oublie pas la taillle de la ligne !!!!!!
void Building::loadToTileSet(std::string const &path)
{
    std::ifstream levelFile(path, std::ios_base::in);

    Floor * currentFloor = new Floor(m_textureLoader->getFloorTexture());

    while(levelFile.good())
    {
        std::string line;
        getline(levelFile, line);

        if(line.length() > 0)
        {
            if(line[0] == '=')
            {
                m_floors.push_back(currentFloor);
                currentFloor = new Floor(m_textureLoader->getFloorTexture());
            }
            std::vector<unsigned char> buffer;
            for(auto it = line.cbegin(); it != line.cend(); ++it)
                buffer.push_back(*it);

            currentFloor->addLine(buffer);
        }
    }
    m_floors.push_back(currentFloor);

	/*
    std::ifstream myfile(path, std::ios_base::in);
	std::vector<unsigned char> buffer;

	char currentChar = ' ';
	unsigned int currentId;
	int currentID = 0;
	int currendFloor = 0;
	std::string test;

	std::string tailleBuffer;
	while(myfile >> currentChar)
	{
		while (currentChar != '=')
			tailleBuffer += myfile.get();
		break;
	}
    */

	//this->setLargeurBuilding(std::stoi(tailleBuffer));

	//std::cout << test;



	//while(myfile >> currentChar)
	//{
	//	
	//	
	//	if(currentChar == '=')
	//	{
	//		std::cout << "endFloor : " << currendFloor << std::endl;
	//		currendFloor++;

	//		m_floors.push_back(new Floor(new std::vector<unsigned char>(buffer),m_textureLoader->getFloorTexture()));
	//		buffer.clear();

	//		currentID = 0;
	//	}

	//	else
	//		buffer.push_back(currentChar);
	//}
}
 