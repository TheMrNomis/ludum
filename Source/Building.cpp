#include "Building.h"

Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage) :
	m_maxBurnedDamage(maxBurnedDamage),
	m_currentBurnedDamage(currentBurnedDamage),
	m_textureLoader(textureLoader),
	m_floors(std::vector<Floor *>()),
	m_currentFloor(0)
{}

Building::~Building()
{
    for(auto it = m_floors.begin(); it != m_floors.end(); ++it)
        delete *it;
}

std::vector<Floor * > * Building::getFloors()
{
	return &m_floors;
}

unsigned int Building::getCurrentFloor()
{
	return m_currentFloor;
}

bool Building::checkCollisionWall(unsigned int idFloor,sf::Sprite & sprite)
{
    //TODO
	return false;
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
            else if(line[0] == 'o')
            {
                //object
                //TODO
            }
            else if(line[0] == 'f')
            {
                //fire detector
                //TODO
            }
            else if(line[0] == 'r')
            {
                //room
                //TODO
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
}

void Building::draw(sf::RenderWindow *window) const
{
	m_floors[m_currentFloor]->draw(window);
}

void Building::update(sf::Clock const & clk)
{
    for(auto it = m_floors.begin(); it != m_floors.end(); ++it)
        (*it)->update(clk);
}




