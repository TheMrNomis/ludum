#include "Building.h"




Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage):
	m_maxBurnedDamage(maxBurnedDamage), 
	m_currentBurnedDamage(currentBurnedDamage),

	m_textureLoader(textureLoader),

	m_floors(std::vector<Floor *>()),
	m_walls(std::vector<Wall *>()),
	m_currentFloor(0)
{
	
}

Building::~Building()
{
}

void Building::initWalls(std::vector<std::vector<unsigned char> > map)
{
	for (unsigned int i = 0; i < map.size(); ++i)
		for (unsigned int j = 0; j < map[i].size(); ++j)
			if (map[i][j] == '1')
				m_walls.push_back(new Wall(sf::Vector2f(i,j)));
}

std::vector<Wall *> * Building::getWalls()
{
	return &m_walls;
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
            else
            {
                std::vector<unsigned char> buffer;
                for(auto it = line.cbegin(); it != line.cend(); ++it)
                    buffer.push_back(*it);

                currentFloor->addLine(buffer);
            }
        }
    }
    m_floors.push_back(currentFloor);

	initWalls(*currentFloor->getMap());
}
 

std::vector<Floor * > Building::getFloors()
{
	return m_floors;
}



void Building::update()
{
	for (int i = 0; i < m_floors.size(); ++i){
		m_floors[i]->update();
	}
}


bool Building::checkCollisionWall(unsigned int idFloor,sf::Sprite & sprite)
{
	bool intercection= false;
	for(unsigned int i = 0; i< m_floors[idFloor]->getAllSpriteFloorWall()->size(); ++i)
	{
		if (sprite.getGlobalBounds().intersects(m_floors[idFloor]->getAllSpriteFloorWall()->at(i)->getGlobalBounds()))
			intercection = true;
			
	}

	return intercection;
}


unsigned int Building::getCurrentFloor()
{
	return m_currentFloor;
}