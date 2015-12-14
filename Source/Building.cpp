#include "Building.h"

#include <unordered_map>


Building::Building(TextureLoader const * textureLoader, unsigned int maxBurnedDamage, unsigned int currentBurnedDamage):
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

bool Building::checkCollisions(Ray * collisionRay)
{
    m_floors[m_currentFloor]->collision(collisionRay);

    return collisionRay->validIntersectionFound();
}

void Building::loadToTileSet(std::string const &path)
{
    std::ifstream levelFile(path, std::ios_base::in);

	Floor * currentFloor = new Floor(m_textureLoader);

    std::unordered_map<unsigned char, Object*> objects;
    std::unordered_map<unsigned char, bool> objectsSentInRoom;

    std::unordered_map<unsigned char, FireDetector*> fireDetectors;
    std::unordered_map<unsigned char, bool> fireDetectorsSentInRoom;

	bool mapConstruction = false;
	unsigned char roomId = '0';

	unsigned int floorId = 0;

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
                currentFloor = new Floor(m_textureLoader);
            }

            else if(line[0] == 'o')
            {
                //object
                bool error = false;
                if(line.length() >= 6)
                {
                    unsigned char objectID = line[1];
                    unsigned char objectType = line[2];
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

                    Object * obj = Object::fromID(objectType, x, y, m_textureLoader->getObjectsTexture());
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
                bool error = false;
                if(line.length() >= 5)
                {
                    unsigned char fireID = line[1];
                    std::string x_str;
                    std::string y_str;
                    bool first = true;

                    for(unsigned int i = 2; i < line.length(); ++i)
                    {
                        if(line[i] == ':')
                            first = false;
                        else
                            (first? x_str : y_str).push_back(line[i]);
                    }

                    unsigned int x = atoi(x_str.c_str());
                    unsigned int y = atoi(y_str.c_str());

                    FireDetector * fd = new FireDetector(x,y, 128, m_textureLoader->getFireDetectorTexture());
                    fireDetectors.insert(std::pair<unsigned char, FireDetector *>(fireID, fd));
                    fireDetectorsSentInRoom.insert(std::pair<unsigned char, bool>(fireID, false));
                }

                else
                    error = true;

                if(error)
                    std::cerr << "error while loading level '" << path << "' at line " << lineNumber << " : malformed fire detector declaration" << std::endl;
            }

            else if(line[0] == 'r')
            {
                //room
                bool ids_fireDetector = false;

                Room * room = new Room(roomId);
                for(unsigned int i = 1; i < line.length(); ++i)
                {
                    if(line[i] == ':')
                        ids_fireDetector = true;

                    else
                    {
                        unsigned char id = line[i];

                        if(!ids_fireDetector)
                        {
                            //TODO: check if id exists
                            room->addObject(objects[id]);
                            objectsSentInRoom[id] = true;
                        }

                        else
                        {
                            //TODO: check if id exists
                            room->addFireDetector(fireDetectors[id]);
                            fireDetectorsSentInRoom[id] = true;
                        }
                    }
                }

                currentFloor->addRoom(room);
				roomId++;
            }

			else if (line[0] == 'd')
			{
				//doors
				if (line.length() >= 4)
				{
					std::string x_str;
					std::string y_str;

					bool first = true;

					for (unsigned int i = 1; i < line.length(); ++i)
					{
						if (line[i] == ':')
							first = false;
						else
							(first ? x_str : y_str).push_back(line[i]);
					}

					unsigned int x = atoi(x_str.c_str());
					unsigned int y = atoi(y_str.c_str());

					Door * door = new Door(x,y,m_textureLoader->getObjectsTexture());
					currentFloor->addDoor(door);
				}
			}

			else if (line[0] == 't')
			{
				//teleporter
				if (line.length() >= 5)
				{
					std::string x_str;
					std::string y_str;
					unsigned char direction = line[1];

					bool first = true;

					for (unsigned int i = 2; i < line.length(); ++i)
					{
						if (line[i] == ':')
							first = false;

						else
							(first ? x_str : y_str).push_back(line[i]);
					}

					unsigned int x = atoi(x_str.c_str());
					unsigned int y = atoi(y_str.c_str());

					Teleporter * teleporter = new Teleporter(x*32, y*32, m_textureLoader->getTeleporterTexture(),0,direction);
					currentFloor->addTeleporter(teleporter);
				}
			}

			else if(line[0] == '|')
			{
				mapConstruction = !mapConstruction;
			}

			else if(mapConstruction)
			{
				std::vector<unsigned char> buffer;
				for (auto it = line.cbegin(); it != line.cend(); ++it)
					buffer.push_back(*it);

				currentFloor->addLineToRoomsMap(buffer);
			}

            else
            {
                std::vector<unsigned char> buffer;
                for(auto it = line.cbegin(); it != line.cend(); ++it)
                    buffer.push_back(*it);

                currentFloor->addLine(buffer);
            }
        }

		floorId++;
    }

    //delete orphaned objects
    for(auto it = objects.begin(); it != objects.end(); ++it)
        if(!objectsSentInRoom.at(it->first))
            delete it->second;

    //delete orphaned fireDetectors
    for(auto it = fireDetectors.begin(); it != fireDetectors.end(); ++it)
        if(!fireDetectorsSentInRoom.at(it->first))
            delete it->second;

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
