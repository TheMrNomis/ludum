#include "Room.h"

Room::Room():
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

void Room::addFireDetector(FireDetector * fd)
{
    m_fireDetectors.push_back(fd);
}

void Room::extinguishFire()
{
    for(auto it = m_objects.begin(); it != m_objects.end(); ++it)
        (*it)->stopFire();
}

void Room::draw(sf::RenderWindow * window) const{

	for (auto it = m_objects.cbegin(); it != m_objects.cend(); ++it)
		(*it)->draw(window);

	//for (auto it = m_fireDetectors.cbegin(); it != m_fireDetectors.cend(); ++it)
	//	(*it)->draw(window);
}

void Room::update()
{
	//TODO: si le fireDetector détecte le character -> extinguishFire()
}
