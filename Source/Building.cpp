#include "Building.h"

#include <unordered_map>

#include "FireDetector.h"

Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage):
	m_maxBurnedDamage(maxBurnedDamage), 
	m_currentBurnedDamage(currentBurnedDamage),
	m_textureLoader(textureLoader),
	m_floors(std::vector<Floor *>()),
	m_currentFloor(0)
{
	
}

Building::~Building()
{
    for(auto it = m_floors.begin(); it != m_floors.end(); ++it)
        delete *it;
}

void Building::draw(sf::RenderWindow *window) const
{
	m_floors[m_currentFloor]->draw(window);
}

void Building::loadToTileSet(std::string const &path)
{
    std::ifstream levelFile(path, std::ios_base::in);

    Floor * currentFloor = new Floor(m_textureLoader->getFloorTexture());

    std::unordered_map<unsigned char, Object*> objects;
    std::unordered_map<unsigned char, bool> objectsSentInRoom;

    std::unordered_map<unsigned char, FireDetector*> fireDetectors;
    std::unordered_map<unsigned char, bool> fireDetectorsSentInRoom;

    unsigned int lineNumber = 0;
    while(levelFile.good())
    {
        std::string line;
        getline(levelFile, line);
        ++lineNumber;

        if(line.length() > 0)
        {
            if(line[0] == '=')
            {
                //new floor
                m_floors.push_back(currentFloor);
                currentFloor = new Floor(m_textureLoader->getFloorTexture());
            }
            else if(line[0] == 'o')
            {
                //object
                bool error = false;
                if(line.length() >= 5)
                {
                    unsigned char objectID = line[1];
                    object_id objectType = (object_id) line[2];
                    std::string x_str;
                    std::string y_str;
                    bool first = true;
                    for(unsigned int i = 3; i < line.length(); ++i)
                    {
                        if(line[i] == ':')
                            first = false;
                        else
                            (first? x_str : y_str).push_back(line[i]);
                    }
                    int x = atoi(x_str.c_str());
                    int y = atoi(y_str.c_str());

                    Object * obj = createObject(objectType, x, y);
                    objects.insert(std::pair<unsigned char, Object*>(objectID, obj));
                    objectsSentInRoom.insert(std::pair<unsigned char, bool>(objectID, false));
                }
                else
                    error = true;

                if(error)
                    std::cerr << "error while loading level '" << path << "' at line " << lineNumber << " : malformed object declaration" << std::endl;
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

    for(auto it = objects.begin(); it != objects.end(); ++it)
        if(!objectsSentInRoom.at(it->first))
            delete it->second;

    for(auto it = fireDetectors.begin(); it != fireDetectors.end(); ++it)
        if(!fireDetectorsSentInRoom.at(it->first))
            delete it->second;

    m_floors.push_back(currentFloor);
}

std::vector<Floor * > Building::getFloors()
{
    return m_floors;
}



void Building::update()
{
    for(auto it = m_floors.begin(); it != m_floors.end(); ++it)
        (*it)->update();
}


bool Building::checkCollisionWall(unsigned int idFloor,sf::Sprite & sprite)
{
    //TODO
    return false;
}


unsigned int Building::getCurrentFloor()
{
    return m_currentFloor;
}
