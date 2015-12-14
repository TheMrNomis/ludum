#include "Room.h"

Room::Room(unsigned int roomId):
	m_roomId(roomId),
    m_objects(std::vector<Object *>()),
    m_fireDetectors(std::vector<FireDetector *>())
{
}

Room::~Room()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        delete *it;

    for(auto  it = m_fireDetectors.begin(); it != m_fireDetectors.end(); ++it)
        delete *it;
}

void Room::addObject(Object * obj)
{
    m_objects.push_back(obj);
}

std::vector<Object *> Room::getObject()
{
	return m_objects;
}

std::vector<FireDetector *> Room::getfireDetector()
{
	return m_fireDetectors;
}

void Room::addFireDetector(FireDetector * fd)
{
    m_fireDetectors.push_back(fd);
}

void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        (*it)->stopFire();
}

void Room::collision(Ray * ray)
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        (*it)->collision(ray);

    for(auto it = m_fireDetectors.begin(); it != m_fireDetectors.end(); ++it)
        (*it)->collision(ray);
}

void Room::draw(sf::RenderWindow * window, std::vector<std::vector<unsigned char>> * floorMap) const
{
	for (auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
		(*it)->draw(window);

	for (auto it = m_fireDetectors.cbegin(); it != m_fireDetectors.cend(); ++it)
		(*it)->draw(window);
}

void Room::update(sf::Clock const & clk)
{
	for (auto it = m_objects.begin(); it != m_objects.end(); ++it)
		(*it)->update(clk);

	//si le fireDetector d�tecte le character -> extinguishFire()
}

